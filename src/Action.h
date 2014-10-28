//
//  Action.h
//  heinneken
//
//  Created by miguel on 26/10/14.
//
//

#ifndef __heinneken__Action__
#define __heinneken__Action__

#include <stdio.h>
#include "ofMain.h"

class Action
{
public:
    virtual ~Action() {}
    virtual string getAction() =0;
    virtual int getArgAsInt(int index) =0;
};
#endif /* defined(__heinneken__Action__) */

