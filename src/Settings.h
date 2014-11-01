//
//  Settings.h
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#ifndef __carrousel__Settings__
#define __carrousel__Settings__

#include "ofxJSON.h"
#include "ofMain.h"

class Settings{
public:
    static Settings* getInstance();
    ~Settings();
    void load();
    string assetsPath();
    int getWidth();
    int getHeight();
    int getPort();
    
private:
    static Settings* instance;
    Settings();
    Settings(Settings const&);       // Don't Implement
    void operator=(Settings const&); // Don't implement
    
    ofxJSONElement json_file;
    Json::Value getData(string key);
};
#endif /* defined(__carrousel__Settings__) */
