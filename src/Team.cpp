//
//  Team.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "Team.h"
#include "Player.h"

Team::Team(){}

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

    score_text.loadFont(ofToDataPath(Settings::getInstance()->getBoldFont()), 48);
}


int Team::getId(){
    return id;
}

Player *Team::getPlayer(int id){
    return players.at(id);
}

void Team::draw(bool start){
    std::vector<Player*>::const_iterator p;

    for(p=players.begin(); p!=players.end(); ++p){

        (*p)->draw(start);

        ofTranslate(0, Settings::getInstance()->getPlayerHeight() + Settings::getInstance()->getPlayerSeparation());
    }
    ofTranslate(0, -2*(Settings::getInstance()->getPlayerHeight() + Settings::getInstance()->getPlayerSeparation()));
   // ofTranslate(0, - Settings::getInstance()->getPlayerSeparation());


}
void Team::drawWinner(){

    Settings* settings = Settings::getInstance();
    float stringWidth = score_text.stringWidth(ofToString(team_score));
    float stringHeight = score_text.stringHeight(ofToString(team_score));
    ofSetColor(getPlayerScoringColor());
    int team_x = settings->getTeamScoreX(id);
    float team_y = settings->getTeamScoreY() + stringHeight/2;
    if(id == 0){
       score_text.drawString(ofToString(team_score), team_x - stringWidth/2, team_y);
    }else{
        score_text.drawString(ofToString(team_score), team_x - stringWidth/2, team_y);
    }

}

void Team::modifyScore(int value){
    team_score += value;
}
int Team::getScore(){
    return team_score;
}

ofColor Team::getPlayerScoringColor(){
    ofColor color = ofColor(255,255,255,255);
    bool player_0_scored = players.front()->isTouchingCircle();
    bool player_1_scored = players.back()->isTouchingCircle();

    if(player_0_scored && !player_1_scored){
        color =  Settings::getInstance()->getPlayerColor(id, 0);
    }else if(player_1_scored && !player_0_scored){
        color = Settings::getInstance()->getPlayerColor(id, 1);
    }

    return color;

}


void Team::drawTeamScore(){
    Settings* settings = Settings::getInstance();
    float stringWidth = score_text.stringWidth(ofToString(team_score));
    float stringHeight = score_text.stringHeight(ofToString(team_score));
    ofSetColor(getPlayerScoringColor());
    int team_x = settings->getTeamScoreX(id);
    float team_y = settings->getTeamScoreY() + stringHeight/2;
    if(id == 0){
       score_text.drawString(ofToString(team_score), team_x - stringWidth/2, team_y);
    }else{
        score_text.drawString(ofToString(team_score), team_x - stringWidth/2, team_y);
    }

}
vector<Player*> Team::getPlayers(){
    return players;
}
