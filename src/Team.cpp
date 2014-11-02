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