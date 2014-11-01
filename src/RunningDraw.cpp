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
    
    int sw = Settings::getInstance()->getWidth();
    int sh = Settings::getInstance()->getHeight();
    
    //Paint background
    ofBackground(0,0,0);
    //Draw player areas
    ofSetColor(32,32,32);
    int endline = Settings::getInstance()->getEndlineLeft();
    
    int piece_size = Settings::getInstance()->PIECE_SIZE;
    int p1_up = Settings::getInstance()->getPlayerY(1, true);
    int p1_down = Settings::getInstance()->getPlayerY(1, false);
    ofRect(0, p1_up - 10 ,sw, p1_down - p1_up - 10);
    
    int p2_up = Settings::getInstance()->getPlayerY(2, true);
    int p2_down = Settings::getInstance()->getPlayerY(2, false);
    ofRect(0, p2_up - 10 ,sw, p2_down - p2_up - 10);
    
    
    endline = Settings::getInstance()->getEndlineRight();
    
    int p3_up = Settings::getInstance()->getPlayerY(3, true);
    int p3_down = Settings::getInstance()->getPlayerY(3, false);
    
    ofRect(0, p3_up - 10 ,sw, p3_down - p3_up - 10);
    
    int p4_up = Settings::getInstance()->getPlayerY(4, true);
    int p4_down = Settings::getInstance()->getPlayerY(4, false);
    ofRect(0, p4_up - 10 ,sw, p4_down - p4_up - 10);
    
    //Draw team separator line
    ofSetColor (0,0,0);
    
    ofLine(0,sh/2,sw,sh/2);
    
    // Draw blocks
    loopOnBlocks();
    
    //Draw end lines
    endline = Settings::getInstance()->getEndlineLeft();
    ofSetColor(160,0,0);
    

    
}
void RunningDraw::loopOnBlocks(){
    
}

RunningModel* RunningDraw::getRunningModel(){
    return running_model;
}