//
//  Player.h
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#ifndef __heinneken__Player__
#define __heinneken__Player__


#include "Settings.h"
#include "Team.h"
#include "GameBlock.h"

class Player
{
    
public:
    Player();
    Player(int id, Team* team);
    virtual ~Player();
    
    int getId();
    Team* getTeam();
    void draw();
    void drawBlocks();
    
protected:
private:
    int id;
    Team* team;
    std::vector<GameBlock*> blocks;
};


#endif /* defined(__heinneken__Player__) */
