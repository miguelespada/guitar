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
    int x = Settings::getInstance()->getPlayerCenter();
    int y = Settings::getInstance()->getPlayerHeight()/2;
    int radius = Settings::getInstance()->getPlayerRadius();
    ofColor color = Settings::getInstance()->getPlayerColor(team->getId(), id);
    
    if(bDown)
        y += radius * 2;
    else
        y -= radius * 2;
    
    ofSetColor(color);
    ofCircle(x, y, radius);
}

void Player::drawBlocks(){
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b)
        (*b)->draw();
}



