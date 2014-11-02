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
    cout << toString("playerOn") << endl;
}

void PlayerOn::run(Action *_action, Commandable *g){
    if(_action->getAction() == action)
        ((GameLogic *)g)->playerOn(_action->getArgAsInt(0));
}

PlayerOff::PlayerOff(string actionName){
    action = actionName;
    cout << toString("playerOff") << endl;
}

void PlayerOff::run(Action *_action, Commandable *g){
    if(_action->getAction() == action)
        ((GameLogic *)g)->playerOff(_action->getArgAsInt(0));
}


Beat::Beat(string actionName){
    action = actionName;
    cout << toString("beat") << endl;
}

void Beat::run(Action *_action, Commandable *g){
    if(_action->getAction() == action)
        ((GameLogic *)g)->beat();
}

Subbeat::Subbeat(string actionName){
    action = actionName;
    cout << toString("subbeat") << endl;
}

void Subbeat::run(Action *_action, Commandable *g){
    if(_action->getAction() == action)
        ((GameLogic *)g)->subbeat();
}