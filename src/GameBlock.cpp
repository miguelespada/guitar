//
//  GameBlock.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "GameBlock.h"


GameBlock::GameBlock(int pieces_num, bool bDown)
{

    GameBlock::bDown = bDown;
    x = 0;
    pieces = pieces_num;
}

void GameBlock::update(){
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
