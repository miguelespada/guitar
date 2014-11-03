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
}

void GameBlock::update(){
    x = x - Settings::getInstance()->getMoveSize();
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

void GameBlock::setX(float x){
    GameBlock::x = x;
}
void GameBlock::setNumberOfPieces(int num){
    GameBlock::pieces = num;
}
int GameBlock::getNumberOfPieces(){
    return GameBlock::pieces;
}
int GameBlock::pieceAtTheEnd(){
    int endline_x = Settings::getInstance()->getPlayerCenterX() + Settings::getInstance()->getPlayerOuterRadius();
    int piece_size = Settings::getInstance()->PIECE_SIZE;

    for(int i = last_touching_piece; i < pieces; i++){
        if((i* piece_size + x )<= endline_x && ((i+1)*piece_size + x > endline_x)){
            //Piece touching endline
            last_touching_piece = i;
            return i;
        }
    }
    return -1; // Piece not touching endline
}

bool GameBlock::hasPassedCircle(){
    int endline_x_left = Settings::getInstance()->getPlayerCenterX() - Settings::getInstance()->getPlayerInnerRadius();
    int width = Settings::getInstance()->PIECE_SIZE * pieces;
    int right_side = x + width;

    return right_side < endline_x_left;
}

bool GameBlock::isEnabled(){
    return enabled;
}


bool GameBlock::isInsideCircle(){
    int endline_x_right = Settings::getInstance()->getPlayerCenterX() + Settings::getInstance()->getPlayerOuterRadius();
    int endline_x_left = Settings::getInstance()->getPlayerCenterX() - Settings::getInstance()->getPlayerInnerRadius();
    int width = Settings::getInstance()->PIECE_SIZE * pieces;

    int right_side = x + width;

    bool leftside_passed_rightcircle = x < endline_x_right;
    bool rightside_not_passed_leftcircle = right_side > endline_x_left;

    return (leftside_passed_rightcircle && rightside_not_passed_leftcircle);
}

bool GameBlock::isTouchingEnd(){
    return pieceAtTheEnd() > -1;
}

bool GameBlock::isOutOfMap(){
        return (x + (pieces * Settings::getInstance()->PIECE_SIZE)) < 0;
}

int GameBlock::getScore(){
    return getNumberOfTouchedPieces() * Settings::getInstance()->PIECE_SCORE;
}
int GameBlock::getLastTouchingPiece(){
    return last_touching_piece;
}

void GameBlock::setPieceTouched(int index){
    piece_touched[index] = true;
}

int GameBlock::getNumberOfTouchedPieces(){
    int counter = 0;
    for (int i = 0; i < getNumberOfPieces(); i++){
        if (piece_touched[i]){
            counter++;
        }
    }
    return counter;
}

