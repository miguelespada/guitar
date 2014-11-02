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
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            getRunningModel()->getPlayer(i,j)->updateBlocks();
        }
    }
}

void RunningLogic::generateBlocks(){
    RunningModel* model = getRunningModel();
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            int block_pieces = ofRandom(1, 6);
            bool position_down = ofRandom(0,1);
            //if (model->getPlayer(i,j)->getRemainingPieces() >= block_pieces){
                if (ofRandom(0,100) < 12){
                    model->addNewBlock(i, j, position_down, block_pieces);
                }
            //}
        }
    }
    model = NULL;
}

