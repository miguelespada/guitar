//
//  Action.cpp
//  heinneken
//
//  Created by miguel on 26/10/14.
//
//

#include "OscAction.h"

OscAction::OscAction(ofxOscMessage _m){
    m = _m;
}

string OscAction::getAction(){
    return m.getAddress();
}

int OscAction::getArgAsInt(int index){
    return m.getArgAsInt32(index);
}