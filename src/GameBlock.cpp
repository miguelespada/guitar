//
//  GameBlock.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "GameBlock.h"
#include "Block.h"

GameBlock::GameBlock()
{
    piece_on = -1;
    piece_off = -1;
}

GameBlock::GameBlock(int id, int player, int pieces_num, bool is_left_painted)
{
}

GameBlock::~GameBlock()
{
    //dtor
}
int GameBlock::y(){
    return getRectangle().y;
}
int GameBlock::x(){
    return getRectangle().x;
}
int GameBlock::height(){
    return getRectangle().height;
}
int GameBlock::width(){
    return getRectangle().width;
}
void GameBlock::setY(int value){
    getRectangle().y = value;
}
void GameBlock::setX(int value){
    getRectangle().x = value;
}
void GameBlock::setHeight(int value){
    getRectangle().height = value;
}
void GameBlock::setWidth(int value){
    getRectangle().width = value;
}
ofRectangle& GameBlock::getRectangle(){
    return rectangle;
}
int GameBlock::getPieces(){
    return pieces;
}
int GameBlock::getPlayerNumber(){
    return player_number;
}

int GameBlock::pieceTouchingEndLine(){
}

bool GameBlock::isOutOfMap(){
}

void GameBlock::setId(int value){
    block_id = value;
}

int GameBlock::getId(){
    return block_id;
}


bool GameBlock::isLeftPainted(){
    return left_painted;
}

void GameBlock::updatePosition(){
    if (isLeftPainted()){
        setX(x()-1);
    } else{
        setX(x()+1);
    }
}
