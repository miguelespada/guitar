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
    void setX(int x);
    void setNumberOfPieces(int num);
    void paintBlock(int y);
    int pieceAtTheEnd();
    bool isOutOfMap();

private:
    int x;
    bool bDown;
    ofColor block_color;
    int pieces; // Number of pieces
    int piece_on; // Piece where player pressed on
    int piece_off; // Piece where player pressed off
};

#endif /* defined(__heinneken__GameBlock__) */
