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
}

RunningModel* RunningDraw::getRunningModel(){
    return running_model;
}

void RunningDraw::drawTeams(){
    vector<Team*>  teams = running_model->getTeams();
    
    std::vector<Team*>::const_iterator t;
    for(t=teams.begin(); t!=teams.end(); ++t)
        (*t)->draw();
}
