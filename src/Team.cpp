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

    score_text.loadFont(ofToDataPath(Settings::getInstance()->getBoldFont()), 48*SCALE);
    big_score_text.loadFont(ofToDataPath(Settings::getInstance()->getBoldFont()), 76*SCALE);
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
    float stringWidth = big_score_text.stringWidth(ofToString(team_score));
    float stringHeight = big_score_text.stringHeight(ofToString(team_score));
    ofSetColor(getPlayerScoringColor());
    float team_x = settings->getTeamScoreX(id) - stringWidth/2;
    float x_margin = settings->getPlayerMargin()*3;
    float team_y = settings->getTeamScoreY() + stringHeight/2;
    float aux_team_x = team_x;

    if(id == 0){
        aux_team_x += x_margin;
    }else{
        aux_team_x -= x_margin;
    }

    big_score_text.drawString(ofToString(team_score), aux_team_x , team_y);
    drawWinnerPlayer(aux_team_x + stringWidth/2, team_y);

}

void Team::drawWinnerPlayer(float team_x, float team_y){

    Settings* settings = Settings::getInstance();
    float x_margin = settings->getPlayerMargin()*3;

    std::vector<Player*>::const_iterator p;
    for(p=players.begin(); p!=players.end(); ++p){
        int score = (*p)->getPlayerScore();

        float stringWidth = score_text.stringWidth(ofToString(score));
        float stringHeight = score_text.stringHeight(ofToString(score));
        ofSetColor(settings->getPlayerColor(id, (*p)->getId()));
        float aux_team_x = team_x - stringWidth/2;
        float aux_team_y = settings->getHeaderHeight() + settings->getPlayerCenterY() - stringHeight/2;

        if((*p)->getId() == 0){
            aux_team_y += settings->getPlayerMargin();
        }else{
            aux_team_y += settings->getPlayerHeight() + settings->getPlayerSeparation() - settings->getPlayerMargin();
        }

        score_text.drawString(ofToString(score), aux_team_x , aux_team_y);
    }

    float aux_team_y = settings->getHeaderHeight() + settings->getPlayerCenterY();
    ofSetColor(255);

    winner_image.draw(team_x - (winner_image.getWidth()/2)*SCALE, (team_y + aux_team_y)/2 - (winner_image.getHeight()/2)*SCALE, winner_image.getWidth()*SCALE, winner_image.getHeight()*SCALE);
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
    float team_x = settings->getTeamScoreX(id);
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

void Team::setWinner(bool winner){
    winner_image = Settings::getInstance()->getRandomPhrase(winner);
    Team::winner = winner;
}
