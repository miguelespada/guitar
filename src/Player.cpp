//
//  Player.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "Player.h"
#include "MidiAdapter.h"

#define DEBUG true

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


int Player::getGlobalId(){
    return team->getId() * 2 + id;
}

Team* Player::getTeam(){
    return team;
}

void Player::setOn(){
    bDown = true;
    height = -(y_down - y_up);
}

void Player::setOff(){
    bDown = false;
    height = 0;
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
    int y =  bDown ? y_down : y_up;
    
    // TODO: color should go to constructor
    color = Settings::getInstance()->getPlayerColor(team->getId(), id);

    ofPath icon;
    icon.setFillColor(color);
    
    //upper cap
    icon.arc(x, y + height, inner_radius, inner_radius, 180, 360);
    icon.close();
    icon.arc(x, y + height, outer_radius, outer_radius, 180, 360);
    icon.draw();
    icon.clear();
    
    //lower cap
    icon.arc(x, y, inner_radius, inner_radius, 0, 180);
    icon.close();
    icon.arc(x, y, outer_radius, outer_radius, 0, 180);
    icon.draw();
    icon.clear();
    
    //side cap
    icon.rectangle(x + inner_radius, y, outer_radius - inner_radius, height);
    icon.rectangle(x - inner_radius, y, -outer_radius + inner_radius, height);
    icon.draw();
    
    height *= 0.8;
}

void Player::update(){
    updateInBlock();
    updateBlocks();
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
    if(DEBUG){
        return bDown;
    }
    
    return false;
}

void Player::enterBlock(){
    ofLogVerbose() << "[Player] enter block ";
    MidiAdapter::getInstance()->sendNoteOn(getGlobalId());
}

void Player::exitBlock(){
    ofLogVerbose() << "[Player] exit block ";
    MidiAdapter::getInstance()->sendNoteOff(getGlobalId());
}

void Player::updateBlocks(){
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b){
        (*b)->update();
    }
}

void Player::drawBlocks(){
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b){
        int yy = (*b)->isDown() ? y_down : y_up ;
        (*b)->draw(yy - inner_radius);
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


