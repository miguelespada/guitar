//
//  GameLogic.cpp
//  heinneken
//
//  Created by miguel on 26/10/14.
//
//

#include "GameLogic.h"
#include "GameLogicCommand.h"

#define DEBUG true

GameLogic::GameLogic(){
    commands.push_back(new PlayerOn("/player_on"));
    commands.push_back(new PlayerOff("/player_off"));
    commands.push_back(new Beat("/beat"));
    commands.push_back(new Subbeat("/subbeat"));
    commands.push_back(new Compass("/compass"));
    constructRunningServices();
    
    setSpeed(1);
};


GameLogic::~GameLogic(){
    destroyRunningServices();
    destroyCommands();
};

void GameLogic::notify(Action *action){
    run(action);
};

void GameLogic::draw(){
    running_draw->draw();
};

void GameLogic::update(){
    if(bSubbeat){
        running_logic->update();
        bSubbeat = false;
    }
    if(bBeat){
        running_logic->generateBlocks();
        bBeat = false;
    }
}

void GameLogic::playerOn(int value){
    running_logic->playerOn(value);
}

void GameLogic::playerOff(int value){
    running_logic->playerOff(value);
}

void GameLogic::beat(){
    bBeat = true;
}

void GameLogic::subbeat(){
    running_model->incrementBeatCounter();
    bSubbeat = true;
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

void GameLogic::setSpeed(int v){
    Settings::getInstance()->setSpeed(v);
}
