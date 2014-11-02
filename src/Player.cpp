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
    inBlock = false;
    x = Settings::getInstance()->getPlayerCenterX();
    int y = Settings::getInstance()->getPlayerHeight()/2;
    outer_radius = Settings::getInstance()->getPlayerOuterRadius();
    inner_radius = Settings::getInstance()->getPlayerInnerRadius();
    y_up = y - Settings::getInstance()->getPlayerCenterY()/2;
    y_down = y + Settings::getInstance()->getPlayerCenterY()/2;
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
    int yy =  bDown ? y_down : y_up;
    
    // TODO: this have to go to constructor
    color = Settings::getInstance()->getPlayerColor(team->getId(), id);

    ofSetColor(color);
    ofCircle(x, yy, outer_radius);
    
    // TODO: draw a hole
    ofSetColor(0);
    ofCircle(x, yy, inner_radius);
}

void Player::update(){
    updateBlocks();
}

void Player::drawBlocks(){
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b){
        int y = (*b)->isDown() ? y_down : y_up ;
        (*b)->draw(y - inner_radius);
    }
}

void Player::updateInBlock(){
    bool prevInBlock = inBlock;
    inBlock = getInBlock();
    
    if(prevInBlock && !inBlock)
        exitBlock();
    
    if(!prevInBlock && inBlock)
        enterBlock();
}

bool Player::getInBlock(){
    //  TODO: compute is a player is in block
    return false;
}

void Player::enterBlock(){
    // TODO: send note on
}

void Player::exitBlock(){
    // TODO: send note off
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


