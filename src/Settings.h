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

#define SCALE 2

class Settings{
public:
    static Settings* getInstance();
    ~Settings();
    void load();
    string assetsPath();
    int getWidth();
    int getHeight();
    int getPort();
    
    int getHeaderHeight();

    //Game variables
    float getPlayerHeight();
    float getPlayerSeparation();
    float getTeamSeparation();
    float getPlayerCenterX();
    float getPlayerCenterY();
    float getPlayerOuterRadius();
    float getPlayerInnerRadius();
    float getPlayerMargin();

    ofColor getPlayerColor(int team, int id);

    const int PIECE_SIZE = 15;
    const int MAX_BLOCK_PIECES = 20;
    const int MAX_PLAYER_PIECES = 150;
    const int BLOCK_SEPARATION = 30;


    // Color constants //

    const ofColor RUNNING_BACKGROUND = ofColor(0, 0, 0);
    const ofColor PLAYER_BACKGROUND = ofColor(100, 0, 0);

private:
    static Settings* instance;
    Settings();
    Settings(Settings const&);       // Don't Implement
    void operator=(Settings const&); // Don't implement

    ofxJSONElement json_file;
    Json::Value getData(string key);

};
#endif /* defined(__carrousel__Settings__) */
