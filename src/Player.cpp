//
//  Player.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "Player.h"

Player::Player(){
    //ctor
}

Player::Player(int id, Team* team){
    Player::id = id;
    Player::team = team;
    x = Settings::getInstance()->getPlayerCenterX();
    int y = Settings::getInstance()->getPlayerHeight()/2;
    outer_radius = Settings::getInstance()->getPlayerOuterRadius();
    inner_radius = Settings::getInstance()->getPlayerInnerRadius();
    y_up = y - Settings::getInstance()->getPlayerCenterY()/2;
    y_down = y + Settings::getInstance()->getPlayerCenterY()/2;

//    for(int i = 0; i < 3; i++){
//        GameBlock* b = new GameBlock(1, true, Settings::getInstance()->getPlayerColor(team->getId(),id));
//        blocks.push_back(b);
//    }
//    GameBlock* b = new GameBlock(1, false, Settings::getInstance()->getPlayerColor(team->getId(),id));
//    b->setX(60);
//    blocks.push_back(b);

}

Player::~Player(){
    //dtor
}

int Player::getId(){
    return id;
}

Team* Player::getTeam(){
    return team;
}

void Player::setOn(){
    bDown = true;
}

void Player::setOff(){
    bDown = false;
}

void Player::draw(){
    ofPushStyle();

    drawBackground();
    drawIcon();
    drawBlocks();

    ofPopStyle();
}

void Player::drawBackground(){
    ofColor background = Settings::getInstance()->PLAYER_BACKGROUND;
    int width = Settings::getInstance()->getWidth();
    int height = Settings::getInstance()->getPlayerHeight();

    ofSetColor(background);
    ofRect(0, 0, width, height);
}

void Player::drawIcon(){
    int yy =  y_up;
    if(bDown) yy =  y_down;

    ofColor color = Settings::getInstance()->getPlayerColor(team->getId(), id);
    ofSetColor(color);

    ofCircle(x, yy, outer_radius);

    ofSetColor(0);
    ofCircle(x, yy, inner_radius);
}

void Player::drawBlocks(){
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b)
        if((*b)->isDown()){
            (*b)->draw(y_down - inner_radius);
        }else{
            (*b)->draw(y_up - inner_radius);
        }
}

void Player::updateBlocks(){
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b){
        (*b)->update();
    }
}

bool Player::hasPlace(bool position_down){
    return position_down ? queue_down == 0 : queue_up == 0;
}

void Player::addNewBlock(bool position_down, int block_pieces){
    if (hasPlace(position_down)){
        blocks.push_back(new GameBlock(block_pieces, position_down, ofColor(255,0,255)));
    } else if (hasPlace(!position_down)){
        blocks.push_back(new GameBlock(block_pieces, !position_down, ofColor(255,0,255)));
    }
}


