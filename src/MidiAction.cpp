//
//  MidiAction.cpp
//  heinneken
//
//  Created by miguel on 30/10/14.
//
//

#include "MidiAction.h"

MidiAction::MidiAction(string msg, int _value){
    action = msg;
    value = _value;
    
}

string MidiAction::getAction(){
    return action;
}

int MidiAction::getArgAsInt(int index){
    return value;
};