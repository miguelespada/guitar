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
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            getRunningModel()->getPlayer(i, j)->update();
            getRunningModel()->getPlayer(i, j)->decrementQueues();
        }
    }
}


void RunningLogic::generateBlocks(){
    cout << "generating" << endl;
    RunningModel* model = getRunningModel();
    for (int team = 0; team < 2; team++){
        for (int player = 0; player < 2; player++){
            int block_pieces = round(ofRandom(1,4));
            bool position_down = round(ofRandom(0,1));
            ofColor color = Settings::getInstance()->getPlayerColor(team, player);
            //if (ofRandom(0,100) < 12){
                model->addNewBlock(team, player, position_down, block_pieces, color);
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

