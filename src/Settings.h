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

#define SCALE 3

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
    int getSmallHeaderPanelWidth();
    int getBigHeaderPanelWidth();
    int getHeaderPanelHeight();

    float getPlayerHeight();
    float getPlayerSeparation();
    float getTeamSeparation();
    float getPlayerCenterX();
    float getPlayerCenterY();
    float getPlayerOuterRadius();
    float getPlayerInnerRadius();
    float getPlayerMargin();
    int getNumberOfSongs();
    int getSpeed();
    void setSpeed(int _speed);
    string getMidiIn();
    string getMidiOut();
    
    ofColor getColor(string colorName);

    int getBlockSeparation();
    float getTeamScoreX(int team);

    ofColor getPlayerColor(int team, int id);

    const float PIECE_SIZE = 181/(2*16) * SCALE;
    const int MAX_BLOCK_PIECES = 20;
    const int MAX_PLAYER_PIECES = 150;
    const int BLOCK_SEPARATION = 2;
    const int PIECE_WIDTH = getPlayerInnerRadius() * 2;
    const int PIECE_SCORE = 10;

    float getMoveSize();
    int getScale();

private:
    static Settings* instance;
    Settings();
    Settings(Settings const&);       // Don't Implement
    void operator=(Settings const&); // Don't implement

    ofxJSONElement json_file;
    Json::Value getData(string key);
    int speed = 3;

};
#endif /* defined(__carrousel__Settings__) */
