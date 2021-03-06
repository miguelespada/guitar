//
//  RunningModel.h
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#ifndef __heinneken__RunningModel__
#define __heinneken__RunningModel__

#include "Player.h"
#include "Team.h"
#include "GameBlock.h"
#include "Assets.h"

class RunningModel
{

public:
    RunningModel();
    virtual ~RunningModel();
    std::vector<Team*> getTeams();
    Player *getPlayer(int team, int id);

    void addNewBlock(int team, int player_number, bool position_down, int block_pieces);

    int getBeatCounter();
    void incrementBeatCounter();
protected:
private:
    std::vector<Team*> teams;
    int beatCounter = 0;

};

#endif /* defined(__heinneken__RunningModel__) */
