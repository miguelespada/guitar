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

class RunningModel
{
    
public:
    RunningModel();
    virtual ~RunningModel();
    std::vector<Team*> getTeams();
    
protected:
private:
    std::vector<Team*> teams;

};

#endif /* defined(__heinneken__RunningModel__) */
