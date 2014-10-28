//
//  Observer.h
//  heinneken
//
//  Created by miguel on 23/10/14.
//
//

#ifndef __heinneken__Observer__
#define __heinneken__Observer__

#include "ofMain.h"
#include "Action.h"

class Observer {
public:
    virtual void notify(Action *action) =0;
};
#endif /* defined(__heinneken__Observer__) */
