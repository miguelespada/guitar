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
    bool bDown = false;
    
protected:
private:
    int id;
    Team* team;
    std::vector<GameBlock*> blocks;
    
    void drawBlocks();
    void drawBackground();
    void drawIcon();
};


#endif /* defined(__heinneken__Player__) */
