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
    cout << "Creating Osc adapter" << endl;
}


OscAdapter::~OscAdapter(){
    cout << "Destroying Osc adapter" << endl;
}

void OscAdapter::init(){
    
    Settings* settings = Settings::getInstance();
    receiver.setup(settings->getPort());
    cout << "listening for osc messages on port " << settings->getPort() << "\n";
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
        cout << "[OSC] Received " << m.getAddress() << endl;
        OscAction *action = new OscAction(m);
        observer->notify(action);
        delete(action);
    }
}

void OscAdapter::update(){
    processMessages();
}
