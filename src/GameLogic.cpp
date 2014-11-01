//
//  GameLogic.cpp
//  heinneken
//
//  Created by miguel on 26/10/14.
//
//

#include "GameLogic.h"
#include "GameLogicCommand.h"

GameLogic::GameLogic(){
    commands.push_back(new PlayerOn("/player_on"));
    commands.push_back(new PlayerOff("/player_off"));
    commands.push_back(new Beat("/beat"));
    
    constructRunningServices();
};


GameLogic::~GameLogic(){
    destroyRunningServices();
    std::vector<Command*>::const_iterator c;
    for(c=commands.begin(); c!=commands.end(); ++c)
        delete *c;
};

void GameLogic::notify(Action *action){
    run(action);
};

void GameLogic::draw(){
    running_draw->draw();
    if(bTempo)
        bTempo = false;
    
};

void GameLogic::update(){
    running_logic->updateBlocks();
}

void GameLogic::playerOn(int value){
    running_logic->playerOn(value);
}

void GameLogic::playerOff(int value){
    
    running_logic->playerOff(value);
}

void GameLogic::beat(){
    bTempo = true;
}


void GameLogic::constructRunningServices(){
    running_model = new RunningModel();
    running_logic = new RunningLogic(running_model);
    running_draw = new RunningDraw(running_model);
}

void GameLogic::destroyRunningServices(){
    delete(running_model);
    delete(running_logic);
    delete(running_draw);
    running_model = NULL;
    running_logic = NULL;
    running_draw = NULL;
}
