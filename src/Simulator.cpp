//
//  OscSimulator.cpp
//  heinneken
//
//  Created by miguel on 27/10/14.
//
//

#include "Simulator.h"

Simulator::Simulator(){
    sender.setup("127.0.0.1", 8080);
}

void Simulator::key_down(){
    ofxOscMessage m;
    m.setAddress("/key_down");
    sender.sendMessage(m);
}

void Simulator::playerOn(int player){
    ofxOscMessage m;
    m.setAddress("/player_on");
    m.addIntArg(player);
    sender.sendMessage(m);
}

void Simulator::playerOff(int player){
    ofxOscMessage m;
    m.setAddress("/player_off");
    m.addIntArg(player);
    sender.sendMessage(m);
}

void Simulator::sendMidiBeat(){
    ofxOscMessage m;
    m.setAddress("/beat");
    m.addIntArg(0);
    sender.sendMessage(m);
}

void Simulator::sendMidiSubbeat(){
    ofxOscMessage m;
    m.setAddress("/subbeat");
    m.addIntArg(0);
    sender.sendMessage(m);
}