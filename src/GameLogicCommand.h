//
//  GameLogicCommand.h
//  heinneken
//
//  Created by miguel on 26/10/14.
//
//

#ifndef __heinneken__GameLogicCommand__
#define __heinneken__GameLogicCommand__

#include "ofMain.h"
#include "Commandable.h"


class PlayerOn: public Command{
public:
    PlayerOn(string actionName);
    void run(Action *_action, Commandable *g);
};


class PlayerOff: public Command{
public:
    PlayerOff(string actionName);
    void run(Action *_action, Commandable *g);
};


class Beat: public Command{
public:
    Beat(string actionName);
    void run(Action *_action, Commandable *g);
};


class Subbeat: public Command{
public:
    Subbeat(string actionName);
    void run(Action *_action, Commandable *g);
};





#endif /* defined(__heinneken__GameLogicCommand__) */
