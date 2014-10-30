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
};

GameLogic::~GameLogic(){
    std::vector<Command*>::const_iterator c;
    for(c=commands.begin(); c!=commands.end(); ++c)
        delete *c;
};

void GameLogic::notify(Action *action){
    run(action);
};

void GameLogic::draw(){
    if(bTempo){
        ofRect(100,  100, 50, 50);
        bTempo = false;
    }
};
void GameLogic::playerOn(int value){
    cout << "Player on: "  << value << endl;
}

void GameLogic::playerOff(int value){
    cout << "Player off: "  << value << endl;
}

void GameLogic::beat(){
    bTempo = true;
}
