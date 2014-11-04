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

#define N 6
class GameBlock
{
public:
    GameBlock();
    ~GameBlock(){};
    GameBlock(int length, bool bDown, ofColor bColor);

    void update();
    void draw(int y);
    bool isDown();
    void setBlockColor(ofColor color);
    void setX(float x);
    int getNumberOfPieces();
    void setNumberOfPieces(int num);
    void paintBlock(int y);
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
private:

    int last_touching_piece = 0;
    float x;
    bool bDown;
    bool piece_touched[N] = {false};
    ofColor block_color;
    int pieces; // Number of pieces
    bool enabled;

};

#endif /* defined(__heinneken__GameBlock__) */
