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
    void setOn();
    void setOff();
    
protected:
private:
    int id;
    Team* team;
    std::vector<GameBlock*> blocks;
    bool bDown = false;
    ofColor color;
    
    
    void drawBlocks();
    void drawBackground();
    void drawIcon();
    
    int x, y_up, y_down, outer_radius, inner_radius;
};


#endif /* defined(__heinneken__Player__) */
