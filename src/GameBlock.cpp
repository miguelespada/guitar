//
//  GameBlock.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "GameBlock.h"


GameBlock::GameBlock(int length, bool bDown)
{
    GameBlock::length = length;
    GameBlock::bDown = bDown;
    x = 0;
    cout << "new block " << endl;
}

void GameBlock::update(){
    x++;
}

void GameBlock::draw(){
}
