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
    int getGlobalId();

    Team* getTeam();

    void draw();
    void setOn();
    void setOff();

    void update();
    void addNewBlock(bool position_down, int block_pieces);

    void modifyScore(int value);

protected:
private:
    int id;
    Team* team;
    int player_score;
    std::vector<GameBlock*> blocks;
    bool bDown = false;
    float height = 0;

    void drawBlocks();
    void drawBackground();
    void drawIcon();
    void drawScore();
    void drawGradients();

    bool hasPlace(bool position_down);
    void incrementQueue(bool position_down, int block_pieces);
    void decrementQueues();

    int queue_up;
    int queue_down;

    int x, y_up, y_down, outer_radius, inner_radius;
    void updateBlocks();
    void updateInBlock();
    bool inBlock;
    bool getInBlock();
    void enterBlock();
    void exitBlock();

};


#endif /* defined(__heinneken__Player__) */
