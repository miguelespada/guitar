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
    x = Settings::getInstance()->getPlayerMargin() + Settings::getInstance()->getPlayerWidth();
    pieces = pieces_num;
}

void GameBlock::update(){
    x = x - Settings::getInstance()->getMoveSize() * Settings::getInstance()->getSpeed();
}

void GameBlock::draw(int y, ofColor block_color){
    ofSetColor(255,0,0);
    paintBlock(y, block_color);
}

void GameBlock::paintBlock(int y, ofColor block_color){

    ofRectangle r;
    r.x = x;
    r.y = y;

    r.height = Settings::getInstance()->PIECE_WIDTH;
    r.width = (pieces > 1) ? pieces * Settings::getInstance()->PIECE_SIZE : r.height;
    //ofTranslate(-Settings::getInstance()->getPlayerMargin(), 0);
    ofSetColor(block_color);
    ofRectRounded(r, 10);
   // ofTranslate(Settings::getInstance()->getPlayerMargin(), 0);

}
bool GameBlock::isDown(){
    return bDown;
}

/*void GameBlock::setX(float x){
    GameBlock::x = x;
}*/
void GameBlock::setNumberOfPieces(int num){
    GameBlock::pieces = num;
}
int GameBlock::getNumberOfPieces(){
    return GameBlock::pieces;
}
int GameBlock::pieceAtTheEnd(){
    int endline_x = Settings::getInstance()->getPlayerCenterX() + Settings::getInstance()->getPlayerOuterRadius();
    float piece_size = Settings::getInstance()->PIECE_SIZE;

    for(int i = 0; i < pieces; i++){
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

void GameBlock::setDisabled(){
    enabled = false;
}

bool GameBlock::isEnabled(){
    return enabled;
}


bool GameBlock::isTouchingCircle(){
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
    int touched = getNumberOfTouchedPieces();
    int extra = (touched == pieces) ? 1 : 0;
    return (extra + touched) * Settings::getInstance()->PIECE_SCORE;
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

