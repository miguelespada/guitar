//
//  Team.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "Team.h"
#include "Player.h"

Team::Team()
{
    team_score_text.init(ofToDataPath("FuturaLT-CondensedLight.ttf"), 25);
}

Team::~Team(){
    for (int i = 0; i < players.size(); i++){
        Player* p = players.front();
        players.erase(players.begin());
        delete p;
        p = NULL;
    }
}

Team::Team(int id)
{
    for (int j = 0; j < 2; j++){
        Player* p = new Player(j, this);
        players.push_back(p);
        p = NULL;
    }
    Team::id = id;


    team_score_text.init(ofToDataPath("FuturaLT-CondensedLight.ttf"), 25);
}


int Team::getId(){
    return id;
}

Player *Team::getPlayer(int id){
    return players.at(id);
}

void Team::draw(){
    std::vector<Player*>::const_iterator p;

    for(p=players.begin(); p!=players.end(); ++p){
        if(p == players.begin())
            ofTranslate(0, Settings::getInstance()->getPlayerMargin());
        (*p)->draw();

        ofTranslate(0, Settings::getInstance()->getPlayerHeight() + Settings::getInstance()->getPlayerSeparation());
    }
    ofTranslate(0, - Settings::getInstance()->getPlayerSeparation());



}
void Team::modifyScore(int value){
    team_score += value;
}
int Team::getScore(){
    return team_score;
}
string Team::getTeamScoreToString(){

    //Conversion to string

    string t;
    ostringstream temp;
    temp << team_score;
    t=temp.str();
    return t;

}

ofColor Team::getPlayerScoringColor(){
    ofColor color = ofColor(255,255,255,255);
    bool player_0_scored = players.front()->isTouchingCircle();// && players.front()->hasScored();
    bool player_1_scored = players.back()->isTouchingCircle();// && players.back()->hasScored();

    if(player_0_scored && !player_1_scored){
        color =  Settings::getInstance()->getPlayerColor(id, 0);
    }else if(player_1_scored && !player_0_scored){
        color = Settings::getInstance()->getPlayerColor(id, 1);
    }

    return color;

}


void Team::drawTeamScore(){
    int team_x = Settings::getInstance()->getTeamScoreX(id);

    ofSetLogLevel(OF_LOG_SILENT);
    team_score_text.setText(getTeamScoreToString());
    ofColor color = getPlayerScoringColor();
    team_score_text.setColor(color.r, color.g, color.b, color.a);
    if(id == 0){
        team_score_text.drawLeft(team_x + 5, Settings::getInstance()->getHeaderHeight() / 2);
    }else{
        team_score_text.drawRight(team_x - 5, Settings::getInstance()->getHeaderHeight() / 2);
    }


    ofSetLogLevel(OF_LOG_VERBOSE);
}
vector<Player*> Team::getPlayers(){
    return players;
}
