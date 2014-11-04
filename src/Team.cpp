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

    score_text.loadFont(ofToDataPath("FuturaLT-CondensedLight.ttf"), 25);
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
        if(p == players.begin())
            ofTranslate(0, Settings::getInstance()->getPlayerMargin());
        (*p)->draw(start);

        ofTranslate(0, Settings::getInstance()->getPlayerHeight() + Settings::getInstance()->getPlayerSeparation());
    }
    ofTranslate(0, - Settings::getInstance()->getPlayerSeparation());



}
void Team::drawWinner(){

    int width = Settings::getInstance()->getWidth();
    int height = Settings::getInstance()->getPlayerHeight() * 2;
    ofColor backgroundColor = Settings::getInstance()->getColor("gray");
    ofSetColor(backgroundColor);
    ofRect(0, 0, width, height);



}
void Team::modifyScore(int value){
    team_score += value;
}
int Team::getScore(){
    return team_score;
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
    float stringWidth = score_text.stringWidth(ofToString(team_score));
    float stringHeight = score_text.stringHeight(ofToString(team_score));
    ofSetColor( getPlayerScoringColor());
    if(id == 0){
       score_text.drawString(ofToString(team_score), team_x + 5, Settings::getInstance()->getHeaderHeight() / 2 + stringHeight + 5);
    }else{
        score_text.drawString(ofToString(team_score), team_x -5 - stringWidth, Settings::getInstance()->getHeaderHeight() / 2 + stringHeight + 5);
    }

}
vector<Player*> Team::getPlayers(){
    return players;
}
