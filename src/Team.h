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
    void draw(bool start);
    Player *getPlayer(int id);
    void modifyScore(int value);
    int getScore();
    ofColor getPlayerScoringColor();
    void drawTeamScore();
    vector<Player*> getPlayers();
    void drawWinner();

protected:
private:
    int id;
    vector<Player*> players;
    int team_score = 0;

    ofTrueTypeFont score_text;
};


#endif /* defined(__heinneken__Team__) */
