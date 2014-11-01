//
//  Player.h
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#ifndef __heinneken__Player__
#define __heinneken__Player__


#include "Settings.h"
#include "Team.h"

class Player
{
    
public:
    Player();
    Player(int number, Team* team);
    virtual ~Player();
    
    int getNumber();
    int setNumber(int value);
    int getPoints();
    int setPoints(int value);
    int getFails();
    int setFails(int value);
    int getCombo();
    int setCombo(int value);
    int getMaxCombo();
    int setMaxCombo(int value);
    bool isActive();
    void setActive(bool value);
    int getRemainingPieces();
    int setRemainingPieces(int value);
    void reduceRemainingPieces(int value);
    void increaseRemainingPieces(int value);
    int getLastBlockId();
    int setLastBlockId(int value);
    int getFirstBlockId();
    int setFirstBlockId(int value);
    vector<int>& getBlockIds();
    Team* getTeam();
    bool isLeftPainted();
    
protected:
private:
    bool active;
    int number;
    int points;
    int fails;
    int combo; //Times without failure in a row until now.
    int max_combo;
    int remaining_pieces;
    Team* team;
    vector<int> block_ids;
};


#endif /* defined(__heinneken__Player__) */
