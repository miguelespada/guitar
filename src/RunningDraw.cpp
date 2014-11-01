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
    
}
void RunningDraw::loopOnBlocks(){
    
}

RunningModel* RunningDraw::getRunningModel(){
    return running_model;
}