//
//  Command.h
//  heinneken
//
//  Created by miguel on 23/10/14.

#ifndef __heinneken__Command__
#define __heinneken__Command__

#include "ofMain.h"
#include "Commandable.h"

class Next: public Command{
public:
    Next(string actionName);
    void run(Action *_action, Commandable *g);
};

#endif /* defined(__heinneken__Command__) */
