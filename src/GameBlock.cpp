//
//  GameBlock.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "GameBlock.h"

GameBlock::GameBlock()
{
    piece_on = -1;
    piece_off = -1;
}

GameBlock::GameBlock(int id, int player, int pieces_num, bool is_left_painted)
{
    player_number = player;
    pieces = pieces_num;
    int w = pieces * Settings::getInstance()->PIECE_SIZE;
    piece_on = -1;
    piece_off = -1;
    if(is_left_painted){
        setX(Settings::getInstance()->getBeginRight() - w);
    }else{
        setX(Settings::getInstance()->getBeginLeft());
    }
    
    setY(Settings::getInstance()->getPlayerY(player, true));
    setWidth(w);
    setHeight(Settings::getInstance()->PIECE_SIZE);
    block_id = id;
    left_painted = is_left_painted;
    
    //  cout<< "Pieces per block: " << pieces << " player " << player << endl;
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
    int endline_x = Settings::getInstance()->getEndlineRight();
    int piece_size = Settings::getInstance()->PIECE_SIZE;
    
    for(int i = 0; i < pieces; i++){
        if((i* piece_size + x() )> endline_x){
            //Piece touching endline
            return i;
        }
    }
    return -1; // Piece not touching endline
}

bool GameBlock::isOutOfMap(){
    if(isLeftPainted()){
        //cout << "Wd: " << width() << endl;
        return (x() + width()) < Settings::getInstance()->getEndlineLeft();
    }else{
        return x() > Settings::getInstance()->getBeginRight();
    }
    
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
