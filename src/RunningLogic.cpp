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
    delete running_model;
    running_model = NULL;
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
    //running_model->assets->loop.update();
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            getRunningModel()->getPlayer(i, j)->update();
            getRunningModel()->getPlayer(i, j)->decrementQueues();
        }
    }
}


void RunningLogic::generateBlocks(){
    RunningModel* model = getRunningModel();
    for (int team = 0; team < 2; team++){
        for (int player = 0; player < 2; player++){

            float r = ofRandom(1);
            int block_pieces = 0;
            if(r < 0.4)
                block_pieces = 1;
            else if(r < 0.6)
                block_pieces = 2;
            else if(r < 0.8)
                block_pieces = 3;
            else if(r < 0.9)
                block_pieces = 4;
            else
                block_pieces = 5;

            bool position_down = round(ofRandom(0,1));
            ofColor color = Settings::getInstance()->getPlayerColor(team, player);
            //if (ofRandom(0,100) < 12){
                model->addNewBlock(team, player, position_down, block_pieces);
           // }
        }
    }
    model = NULL;
}

Player* RunningLogic::getPlayer(int player){
    int team = player / 2;
    int id = player % 2;
    return running_model->getPlayer(team, id);
}

