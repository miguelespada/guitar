//
//  OscSimulator.cpp
//  heinneken
//
//  Created by miguel on 27/10/14.
//
//

#include "OscSimulator.h"

OscSimulator::OscSimulator(){
    sender.setup("127.0.0.1", 8080);
}

void OscSimulator::key_down(){
    ofxOscMessage m;
    m.setAddress("/key_down");
    sender.sendMessage(m);
}

void OscSimulator::playerOn(int player){
    ofxOscMessage m;
    m.setAddress("/player_on");
    m.addIntArg(player);
    sender.sendMessage(m);
}

void OscSimulator::playerOff(int player){
    ofxOscMessage m;
    m.setAddress("/player_off");
    m.addIntArg(player);
    sender.sendMessage(m);
}