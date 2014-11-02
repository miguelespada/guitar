//
//  GameBlock.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "GameBlock.h"


GameBlock::GameBlock(int pieces_num, bool bDown, ofColor bColor)
{
    GameBlock::block_color = bColor;
    GameBlock::bDown = bDown;
    x = Settings::getInstance()->getWidth();
    pieces = pieces_num;
    piece_on = -1;
    piece_off = -1;
}

void GameBlock::update(){
    x--;
}

void GameBlock::draw(int y){
    paintBlock(y);
}

void GameBlock::paintBlock(int y){

    ofRectangle r;
    r.x = x;
    r.y = y;
    r.width = pieces * Settings::getInstance()->PIECE_SIZE;
    r.height = Settings::getInstance()->PIECE_WIDTH;

    ofSetColor(block_color);

    ofRectRounded(r, 10);

}
bool GameBlock::isDown(){
    return bDown;
}
void GameBlock::setBlockColor(ofColor color){
    GameBlock::block_color = color;
}

void GameBlock::setX(int x){
    GameBlock::x = x;
}
void GameBlock::setNumberOfPieces(int num){
    GameBlock::pieces = num;
}
int GameBlock::pieceAtTheEnd(){
    int endline_x = Settings::getInstance()->getPlayerCenterX();
    int piece_size = Settings::getInstance()->PIECE_SIZE;

    for(int i = 0; i < pieces; i++){
        if((i* piece_size + x )> endline_x){
            //Piece touching endline
            return i;
        }
    }
    return -1; // Piece not touching endline
}
bool GameBlock::isOutOfMap(){
        return (x + (pieces * Settings::getInstance()->PIECE_SIZE)) < 0;
}
int GameBlock::getPieceOn(){
    return piece_on;
}
int GameBlock::getPieceOff(){
    return piece_off;
}
void GameBlock::setPieceOn(int p){
    piece_on = p;
}
void GameBlock::setPieceOff(int p){
    piece_off = p;
}
int GameBlock::getScore(){
    return (piece_off - piece_on) * Settings::getInstance()->PIECE_SCORE;
}
