//
//  Team.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "Team.h"

Team::Team()
{
    //ctor
}

Team::Team(int team_number)
{
    Team::team_number = team_number;
}


Team::~Team()
{
    //dtor
}


int Team::getTeamNumber(){
    return team_number;
}

void Team::setTeamNumber(int value){
    team_number = value;
}

bool Team::isLeftPainted(){
    if (team_number == 1){
        return true;
    } else{
        return false;
    }
}
