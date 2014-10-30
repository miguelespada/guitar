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

class GameLogic: public Observer, public Commandable
{
public:
    GameLogic();
    ~GameLogic();
    void draw();
    void notify(Action *action);
    void playerOn(int value);
    void playerOff(int value);
    void beat();
    bool bTempo;
};
#endif /* defined(__heinneken__GameLogic__) */
