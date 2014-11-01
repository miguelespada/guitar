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
    GameBlock(int length, bool bDown);
    
    void update();
    void draw();
private:
    int length;
    int x;
    bool bDown;
};

#endif /* defined(__heinneken__GameBlock__) */
