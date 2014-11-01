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
}

Team::Team(int id)
{
    Team::id = id;
}


Team::~Team()
{
    //dtor
}


int Team::getTeamNumber(){
    return id;
}

bool Team::isLeftPainted(){
    return id;
}
