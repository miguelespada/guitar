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

public:
    Player();
    Player(int id, Team* team);
    virtual ~Player();

    int getId();
    int getGlobalId();

    Team* getTeam();

    void draw(bool start);
    void setOn();
    void setOff();

    void update();
    void addNewBlock(bool position_down, int block_pieces, ofColor color);

    bool hasScored();
    void decrementQueues();
    void modifyScore(int value);
    string getPlayerScoreToString();
    void drawPlayerScore();
    void setLastScore(int value);
    bool isTouchingCircle();
    void drawForStarting();

protected:
private:
    void drawIcon();
    ofxTextBlock player_score_text;
    int id;
    Team* team;
    int player_score = 0;
    std::vector<GameBlock*> blocks;
    bool bDown = false;
    float height = 0;
    int last_score = 0;
    void drawBlocks();
    void drawBackground();


    void drawGradients();

    bool hasPlace(bool position_down);
    void incrementQueue(bool position_down, int pieces);

    int queue_up;
    int queue_down;
    int last_block_touching = -1;

    int x, y_up, y_down, outer_radius, inner_radius;
    void updateBlocks();
    void updateInBlock();
    bool inBlock;
    bool getInBlock();
    void enterBlock();
    void exitBlock();


    void updateBlockTouchedPieces();
    GameBlock* getFirstBlockEnabled();

    void eraseBlock(int position);

};


#endif /* defined(__heinneken__Player__) */
