//
//  RunningDraw.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "RunningDraw.h"

RunningDraw::RunningDraw(RunningModel* model){
    running_model = model;
}

RunningDraw::~RunningDraw()
{
    //dtor
}

void RunningDraw::draw(){
    drawTeams();
    drawBlocks();
}

RunningModel* RunningDraw::getRunningModel(){
    return running_model;
}

void RunningDraw::drawBlocks(){
    for(int i = 0; i< getRunningModel()->getBlocks().size(); i++){
        GameBlock block = getRunningModel()->getBlock(i);
        block.draw();
    }
}
