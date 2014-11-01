//
//  RunningModel.h
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#ifndef __heinneken__RunningModel__
#define __heinneken__RunningModel__

#include "Player.h"
#include "Team.h"
#include "GameBlock.h"

class RunningModel
{
    
public:
    RunningModel();
    virtual ~RunningModel();
    std::vector<Team*> getTeams();
    Team* getTeam(int position);
    std::vector<Player*> getPlayers();
    Player* getPlayer(int position);
    std::vector<GameBlock>& getBlocks();
    GameBlock& getBlock(int position);
    void addNewBlock(int player, int pieces);
    void removeBlock(int position);
    int getNumberOfPlayers();
    void setTotalBlocks(int value);
    int getTotalBlocks();
    GameBlock& getBlockById(int id);
    void updateBlock(int position);
protected:
private:
    std::vector<Team*> teams;
    std::vector<Player*> players;
    std::vector<GameBlock> blocks;
    int total_blocks;
};

#endif /* defined(__heinneken__RunningModel__) */
