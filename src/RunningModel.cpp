//
//  RunningModel.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//
#include "RunningModel.h"

RunningModel::RunningModel()
{

    for (int i = 0; i < 2; i++){
        Team* team = new Team(i);
        teams.push_back(team);
        team = NULL;
    }
    Assets::getInstance()->loop.setLoopState(OF_LOOP_NORMAL);

}

RunningModel::~RunningModel()
{
    for (int i = 0; i < teams.size(); i++){
        Team* t = teams.front();
        teams.erase(teams.begin());
        delete t;
        t = NULL;
    }
}

std::vector<Team*> RunningModel::getTeams(){
    return teams;
}

Player* RunningModel::getPlayer(int team, int id){
    return teams.at(team)->getPlayer(id);
}

void RunningModel::addNewBlock(int team, int player_number, bool position_down, int block_pieces){
    getPlayer(team, player_number)->addNewBlock(position_down, block_pieces);
}

int RunningModel::getBeatCounter(){
    return beatCounter;
}

void RunningModel::incrementBeatCounter(){
    beatCounter += 1;
}

