//
//  Commad.cpp
//  heinneken
//
//  Created by miguel on 23/10/14.
//
//

#include "Game.h"
#include "Command.h"
#include "Action.h"

Next::Next(string actionName){
    action = actionName;
     ofLogNotice() << toString("next");
}

void Next::run(Action *_action, Commandable *g){
    if(_action->getAction() == action)
        ((Game *)g)->next();
}

