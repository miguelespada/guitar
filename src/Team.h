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
    void modifyScore(int value);

protected:
private:
    int id;
    vector<Player*> players;
    int team_score;
};


#endif /* defined(__heinneken__Team__) */
