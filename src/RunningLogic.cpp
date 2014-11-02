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
    getPlayer(player)->setOn();
}

void RunningLogic::playerOff(int player){
    getPlayer(player)->setOff();
}

void RunningLogic::update(){

}

void RunningLogic::generateBlocks(){

}

Player* RunningLogic::getPlayer(int player){
    int team = player / 2;
    int id = player % 2;
    return running_model->getPlayer(team, id);
}

