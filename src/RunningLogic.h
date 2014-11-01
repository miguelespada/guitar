//
//  RunningLogic.h
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#ifndef __heinneken__RunningLogic__
#define __heinneken__RunningLogic__

#include "RunningModel.h"
#include "Settings.h"

class RunningLogic
{
public:
    RunningLogic(){};
    RunningLogic(RunningModel* model);
    virtual ~RunningLogic();
    RunningModel* getRunningModel();
    void playerOn(int player);
    void playerOff(int player);
    void updateBlocks();
    void generateBlocks();
    bool isPaintable(int player, int pieces);
protected:
private:
    RunningModel* running_model;
    int generate_player_turn;
};

#endif /* defined(__heinneken__RunningLogic__) */
