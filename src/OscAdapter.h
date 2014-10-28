//
//  OscAdapter.h
//  carrousel
//
//  Created by miguel on 14/10/14.
//
//

#ifndef __game__OscAdapter__
#define __game__OscAdapter__

#include <stdio.h>
#include "Observer.h"
#include "ofxJSON.h"
#include "ofxOsc.h"
#include "Settings.h"

class OscAdapter{
    Observer *observer;
    void processMessages();
    Settings *settings;
public:
    OscAdapter();
    ~OscAdapter();
    bool bOnline;
    
    ofxOscReceiver receiver;
    void registerObserver(Observer *o);
    void init();
    void update();
    void setSettings(Settings *s);
};

#endif /* defined(__carrousel__OscAdapter__) */
