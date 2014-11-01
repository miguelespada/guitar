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
    x = Settings::getInstance()->getPlayerCenter();
    int y = Settings::getInstance()->getPlayerHeight()/2;
    radius = Settings::getInstance()->getPlayerRadius();
    y_up = y - radius * 2;
    y_down = y + radius * 2;
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
    ofColor color = Settings::getInstance()->getPlayerColor(team->getId(), id);
    ofSetColor(color);
    
    if(bDown)
        ofCircle(x, y_down, radius);
    else
        ofCircle(x, y_up, radius);
}

void Player::drawBlocks(){
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b)
        (*b)->draw();
}



