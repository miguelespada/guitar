//
//  OscAdapter.cpp
//  carrousel
//
//  Created by miguel on 14/10/14.
//
//

#include "OscAdapter.h"
#include "OscAction.h"

OscAdapter::OscAdapter(){
    ofLogVerbose() << "Creating Osc adapter";
}


OscAdapter::~OscAdapter(){
    ofLogVerbose() << "Destroying Osc adapter";
}

void OscAdapter::init(){
    
    Settings* settings = Settings::getInstance();
    receiver.setup(settings->getPort());
    ofLogNotice() << "listening for osc messages on port " << settings->getPort();
    bOnline = false;
}

void OscAdapter::registerObserver(Observer *o){
    observer = o;
}

void OscAdapter::processMessages(){
    while(receiver.hasWaitingMessages()){
        bOnline = true;
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        OscAction *action = new OscAction(m);
        observer->notify(action);
        delete(action);
    }
}

void OscAdapter::update(){
    processMessages();
}
