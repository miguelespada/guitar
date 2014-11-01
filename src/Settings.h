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
    
    
    int getPlayerY(int player, bool isUp);
    
    //Game variables
    
    
    int getEndlineRight();
    int getBeginRight();
    int getEndlineLeft();
    int getBeginLeft();
    
    const int PIECE_SIZE = 15;
    const int MAX_BLOCK_PIECES = 20;
    const int MAX_PLAYER_PIECES = 150;
    const int BLOCK_SEPARATION = 30;
    
    // Player positions //
    const int P1_Y = 150;
    const int P2_Y = 250;
    const int P3_Y = 400;
    const int P4_Y = 500;
    
    // Color constants //
    
    const ofColor RUNNING_BACKGROUND = (0,0,0);
    
private:
    static Settings* instance;
    Settings();
    Settings(Settings const&);       // Don't Implement
    void operator=(Settings const&); // Don't implement
    
    ofxJSONElement json_file;
    Json::Value getData(string key);
    
};
#endif /* defined(__carrousel__Settings__) */
