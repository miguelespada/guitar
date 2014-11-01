//
//  RunningLogic.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "RunningLogic.h"

RunningLogic::RunningLogic(RunningModel* model)
{
    running_model = model;
}
RunningLogic::~RunningLogic()
{
    //dtor
}

RunningModel* RunningLogic::getRunningModel(){
    return running_model;
}

void RunningLogic::playerOn(int player){
    int team = player / 2;
    int id = player % 2;
    Player *p = running_model->getPlayer(team, id);
    p->setOn();
}

void RunningLogic::playerOff(int player){
    int team = player / 2;
    int id = player % 2;
    Player *p = running_model->getPlayer(team, id);
    p->setOff();
}

void RunningLogic::update(){

}

void RunningLogic::generateBlocks(){

}

