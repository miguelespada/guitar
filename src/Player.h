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
#include "ofxTextSuite.h"

class Player
{

private:
    int id;
    Team* team;
    std::vector<GameBlock*> blocks;
    bool bDown = false;
    int bonus = 0;

    int queue_up;
    int queue_down;

    int perfect_blocks = 0;
    int last_block_touching = -1;
    int player_score = 0;

    float height = 0;
    int x, y_up, y_down, outer_radius, inner_radius;

    ofxTextBlock player_score_text;

    int last_score = 0;

    int inactivity_counter = 100000;

private:

    void drawBlocks();
    void drawBackground();
    void drawIcon();

    void drawGradients();

    bool hasPlace(bool position_down);
    void incrementQueue(bool position_down, int pieces);

    void updateBlocks();
    void updateInBlock();
    bool inBlock;
    bool getInBlock();
    void enterBlock();
    void exitBlock();


    void updateBlockTouchedPieces();
    GameBlock* getFirstBlockEnabled();

    void eraseBlock(int position);
    int getBlockScore(GameBlock* block);
    void updateInactivityCounter();
    void drawInactivityPanel();

protected:

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

    bool hasScored();
    void decrementQueues();
    void modifyScore(int value);
    string getPlayerScoreToString();
    void drawPlayerScore();
    void setLastScore(int value);
    bool isTouchingCircle();
    int getBonus();
    void setBonus(int value);
    int getPerfectBlocks();
    void setPerfectBlocks(int value);
    void updateBonus();
    ofColor getBlockPaintingColor();
    bool isInactive();

};


#endif /* defined(__heinneken__Player__) */
