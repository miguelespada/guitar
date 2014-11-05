//
//  GameLogic.h
//  heinneken
//
//  Created by miguel on 26/10/14.
//
//

#ifndef __heinneken__GameLogic__
#define __heinneken__GameLogic__

#include <stdio.h>
#include "ofMain.h"
#include "Observer.h"
#include "Commandable.h"

#include "RunningDraw.h"
#include "RunningLogic.h"
#include "RunningModel.h"

class GameLogic: public Observer, public Commandable
{

    RunningLogic* running_logic;
    RunningDraw* running_draw;
    RunningModel* running_model;

public:
    RunningModel* getRunningModel();
    RunningDraw* getRunningDraw();
    void constructRunningServices();
    void destroyRunningServices();
    GameLogic();
    ~GameLogic();
    void draw();
    void update();
    void notify(Action *action);
    void playerOn(int value);
    void playerOff(int value);
    void setSpeed(int v);
    void beat();
    void subbeat();
    bool bBeat, bSubbeat;

};
#endif /* defined(__heinneken__GameLogic__) */
