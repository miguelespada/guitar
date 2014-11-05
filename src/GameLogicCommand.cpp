//
//  GameLogicCommand.cpp
//  heinneken
//
//  Created by miguel on 26/10/14.
//
//

#include "GameLogicCommand.h"
#include "GameLogic.h"

PlayerOn::PlayerOn(string actionName){
    action = actionName;
}

void PlayerOn::run(Action *_action, Commandable *g){
    if(_action->getAction() == action)
        ((GameLogic *)g)->playerOn(_action->getArgAsInt(0));
}

PlayerOff::PlayerOff(string actionName){
    action = actionName;
}

void PlayerOff::run(Action *_action, Commandable *g){
    if(_action->getAction() == action)
        ((GameLogic *)g)->playerOff(_action->getArgAsInt(0));
}


Beat::Beat(string actionName){
    action = actionName;
    ofLogVerbose() << toString("beat");
}

void Beat::run(Action *_action, Commandable *g){
    if(_action->getAction() == action)
        ((GameLogic *)g)->beat();
}

Subbeat::Subbeat(string actionName){
    action = actionName;
    ofLogVerbose() << toString("subbeat");
}

void Subbeat::run(Action *_action, Commandable *g){
    if(_action->getAction() == action)
        ((GameLogic *)g)->subbeat();
}

Compass::Compass(string actionName){
    action = actionName;
    ofLogVerbose() << toString("compass");
}

void Compass::run(Action *_action, Commandable *g){
    if(_action->getAction() == action){
        
    }
}

