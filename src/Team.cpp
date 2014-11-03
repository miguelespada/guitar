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
    formatted_score.init("frabk.ttf", 20);
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
ofxTextBlock Team::getTeamScoreFormatted(){

    //Conversion to string
    string t;
    ostringstream temp;
    temp << team_score;
    t=temp.str();

    ofSetLogLevel(OF_LOG_SILENT);
    formatted_score.setColor(255,255,255,255); //TODO: set text color to white correctly
    formatted_score.setText(t);
    ofSetLogLevel(OF_LOG_VERBOSE);
    return formatted_score;

}
