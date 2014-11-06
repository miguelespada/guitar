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
    void drawWinnerPlayer(float team_x, float team_y);
    void setWinner(bool winner);

protected:
private:
    int id;
    vector<Player*> players;
    int team_score = 0;
    bool winner;

    ofTrueTypeFont score_text;
    ofTrueTypeFont big_score_text;
    ofImage winner_image;
};


#endif /* defined(__heinneken__Team__) */
