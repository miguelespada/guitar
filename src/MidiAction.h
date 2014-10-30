//
//  MidiAction.h
//  heinneken
//
//  Created by miguel on 30/10/14.
//
//

#ifndef __heinneken__MidiAction__
#define __heinneken__MidiAction__

#include <stdio.h>
#include "Action.h"

class MidiAction: public Action
{
    string action;
    int value;
public:
    MidiAction(string msg, int _value);
    ~MidiAction(){};
    
    string getAction();
    int getArgAsInt(int index);
};


#endif /* defined(__heinneken__MidiAction__) */
