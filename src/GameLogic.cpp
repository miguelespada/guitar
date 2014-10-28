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
};

GameLogic::~GameLogic(){
    std::vector<Command*>::const_iterator c;
    for(c=commands.begin(); c!=commands.end(); ++c)
        delete *c;
};

void GameLogic::notify(Action *action){
    run(action);
};

void GameLogic::draw(){};

void GameLogic::playerOn(int value){
    cout << "Player on: "  << value << endl;
}

void GameLogic::playerOff(int value){
    cout << "Player off: "  << value << endl;
}
