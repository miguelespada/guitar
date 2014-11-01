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
    ~GameBlock();
    GameBlock(int id, int player, int pieces_num, bool is_left_painted);
    int getPieces();
    int getPlayerNumber();
    int pieceTouchingEndLine();
    bool isOutOfMap();
    ofRectangle& getRectangle();
    int y();
    int x();
    int height();
    int width();
    void setY(int value);
    void setX(int value);
    void setHeight(int value);
    void setWidth(int value);
    void setId(int value);
    int getId();
    bool isLeftPainted();
    void setLeftPainted(bool value);
    void updatePosition();
    void draw();
private:
    bool left_painted;
    ofRectangle rectangle;
    int player_number;
    int pieces; // Number of pieces
    int piece_on; // Piece where player pressed on
    int piece_off; // Piece where player pressed off
    int block_id;
};

#endif /* defined(__heinneken__GameBlock__) */
