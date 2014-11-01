//
//  RunningModel.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//
#include "RunningModel.h"

RunningModel::RunningModel()
{
    total_blocks = 0;
    
    for (int i = 0; i < 2; i++){
        Team* t = new Team(i+1);
        teams.push_back(t);
        t = NULL;
    }
    
    for (int i = 0; i < 4; i++){
        Player* p = new Player(i+1, getTeam((i/2)+1)); //Team number = 1 or 2
        players.push_back(p);
        p = NULL;
    }
    
    cout << "creating Model" << endl;
    
}

RunningModel::~RunningModel()
{
    for (int i = 0; i < players.size(); i++){
        Player* p = players.front();
        players.erase(players.begin());
        delete p;
        p = NULL;
    }
    
    for (int i = 0; i < teams.size(); i++){
        Team* t = teams.front();
        teams.erase(teams.begin());
        delete t;
        t = NULL;
    }
}

std::vector<Team*> RunningModel::getTeams(){
    return teams;
}

Team* RunningModel::getTeam(int position){
    return teams.at(position-1);
}

std::vector<Player*> RunningModel::getPlayers(){
    return players;
}

Player* RunningModel::getPlayer(int position){
    return players.at(position-1);
}

std::vector<GameBlock>& RunningModel::getBlocks(){
    return blocks;
}

GameBlock& RunningModel::getBlock(int position){
    return blocks.at(position);
}

int RunningModel::getNumberOfPlayers(){
    return getPlayers().size();
}

void RunningModel::addNewBlock(int player, int pieces){
    Player* p = getPlayer(player);
    p->reduceRemainingPieces(pieces);
    int id = getTotalBlocks() + 1;
    blocks.push_back(GameBlock(id, player, pieces + 1, p->isLeftPainted()));
    setTotalBlocks(id);
    p->getBlockIds().push_back(id);
    p = NULL;
}

void RunningModel::removeBlock(int position){
    GameBlock b = getBlock(position);
    Player* p = getPlayer(b.getPlayerNumber());
    p->increaseRemainingPieces(b.getPieces());
    blocks.erase(blocks.begin()+position);
    p->getBlockIds().erase(p->getBlockIds().begin()+position);
    
}
void RunningModel::setTotalBlocks(int value){
    total_blocks = value;
}
int RunningModel::getTotalBlocks(){
    return total_blocks;
}


//Every id exists as ids are created for each block and never removed (the ids)
GameBlock& RunningModel::getBlockById(int id){
    int firstblock_id = blocks.front().getId();
    int position = id - firstblock_id;
    if (position >= 0 && position < blocks.size()){
        return blocks.at(position);
    }
    GameBlock failure = GameBlock(0,0,0, false);
    return failure;
}

void RunningModel::updateBlock(int position){
    getBlock(position).updatePosition();
    if(getBlock(position).isOutOfMap()){
        removeBlock(position);
    }
}
