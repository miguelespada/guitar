//
//  Team.h
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#ifndef __heinneken__Team__
#define __heinneken__Team__

#include "ofMain.h"

class Player;
class Team
{
public:
    Team();
    Team(int team_number);
    virtual ~Team();
    int getId();
    void draw();
    Player *getPlayer(int id);
    
protected:
private:
    int id;
    vector<Player*> players;
};


#endif /* defined(__heinneken__Team__) */
