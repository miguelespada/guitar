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

#define SCALE 0.5

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
    int getIntroTime();
    int getBlockSeparation();
    float getTeamScoreX(int team);
    float getTeamScoreY();

    ofColor getPlayerColor(int team, int id);
    string getFont();
    string getBoldFont();

    //new design
    const float PLAYER_WIDTH = 600 * SCALE;


    const float PIECE_SIZE = getPlayerWidth()/32;
    const int MAX_BLOCK_PIECES = 20;
    const int MAX_PLAYER_PIECES = 150;
    const int BLOCK_SEPARATION = 2;
    const int PIECE_WIDTH = getPlayerInnerRadius() * 2;
    const int PIECE_SCORE = 10;

    float getMoveSize();
    int getScale();
    int getBonusMark(int bonus);
    int getInactivityTime();
    int getTitleRUNNINGChangeTime();
    int getTitleIDLEChangeTime();
    float getPlayerWidth();
    float getCentralImageX();
    float getCentralImageY();
    float getPlayerCentralImageSeparation();
    float getCentralImageHeight();
    float getCentralImageWidth();
private:
    static Settings* instance;
    Settings();
    Settings(Settings const&);       // Don't Implement
    void operator=(Settings const&); // Don't implement

    ofxJSONElement json_file;
    Json::Value getData(string key);
    int speed = 1;


};
#endif /* defined(__carrousel__Settings__) */
