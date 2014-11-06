//
//  GameBlock.h
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#ifndef __heinneken__GameBlock__
#define __heinneken__GameBlock__

#include "ofMain.h"
#include "Settings.h"
#include "Assets.h"

#define N 10
class GameBlock
{

private:
    int last_touching_piece = 0;
    float x;
    //void setX(float x);
    bool bDown;
    bool piece_touched[N] = {false};
    int pieces; // Number of pieces
    bool enabled = true;

public:
    GameBlock();
    ~GameBlock(){};
    GameBlock(int length, bool bDown);

    void update();
    void draw(int y, ofColor block_color, int bonus);
    bool isDown();
    int getNumberOfPieces();
    void setNumberOfPieces(int num);
    void paintBlock(int y, ofColor block_color, int bonus);
    int pieceAtTheEnd();
    bool isOutOfMap();
    int getScore();
    int getLastTouchingPiece();
    bool isTouchingEnd();
    bool isTouchingCircle();
    void setPieceTouched(int index);
    int getNumberOfTouchedPieces();


    bool hasPassedCircle();
    bool isEnabled();
    void setDisabled();


};

#endif /* defined(__heinneken__GameBlock__) */
