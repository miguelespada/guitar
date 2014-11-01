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
