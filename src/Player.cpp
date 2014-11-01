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

Player::Player(int number, Team* team){
    Player::number = number;
    Player::team = team;
    active = false;
    remaining_pieces = Settings::getInstance()->MAX_PLAYER_PIECES;
}

Player::~Player(){
    //dtor
}

int Player::getNumber(){
    return number;
}
int Player::setNumber(int value){
    number = value;
}
int Player::getPoints(){
    return points;
}
int Player::setPoints(int value){
    points = value;
}
int Player::getFails(){
    return fails;
}
int Player::setFails(int value){
    fails = value;
}
int Player::getCombo(){
    return combo;
}
int Player::setCombo(int value){
    combo = value;
    if (combo > max_combo) {
        setMaxCombo(combo);
    }
}
int Player::getMaxCombo(){
    return max_combo;
}
int Player::setMaxCombo(int value){
    max_combo = value;
}

bool Player::isActive(){
    return active;
}

void Player::setActive(bool value){
    active = value;
}

int Player::getRemainingPieces(){
    return remaining_pieces;
}

int Player::setRemainingPieces(int value){
    remaining_pieces = value;
}

void Player::reduceRemainingPieces(int value){
    remaining_pieces -= value;
}
void Player::increaseRemainingPieces(int value){
    remaining_pieces += value;
}

int Player::getLastBlockId(){
    if (block_ids.size() > 0){
        return block_ids.back();
    } else{
        return 0;
    }
}

int Player::getFirstBlockId(){
    if (block_ids.size() > 0){
        return block_ids.front();
    } else{
        return 0;
    }
}

vector<int>& Player::getBlockIds(){
    return block_ids;
}

Team* Player::getTeam(){
    return team;
}

bool Player::isLeftPainted(){
    return team->isLeftPainted();
}


