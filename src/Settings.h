//
//  Settings.h
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#ifndef __carrousel__Settings__
#define __carrousel__Settings__

#include <stdio.h>
#include "ofxJSON.h"
#include "ofMain.h"

class Settings{
    ofxJSONElement settings;
public:
    Settings();
    ~Settings();
    
    void load();
    string assetsPath();
    
    int width, height;
    int port;
};
#endif /* defined(__carrousel__Settings__) */
