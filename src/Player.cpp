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
    cout << "Draw player: " << team->getId() << "," << id << endl;
}


void Player::drawBlocks(){
        
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b)
        (*b)->draw();
    
}



