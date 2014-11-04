//
//  Settings.cpp
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#include "Settings.h"

Settings::Settings(){
    ofLogVerbose() << "Constructing Settings ";

}
Settings::~Settings(){
    ofLogVerbose() << "Destroying Settings ";
}

Settings* Settings::instance = 0;
Settings* Settings::getInstance(){
    if (instance == 0){
        instance = new Settings();
        instance->load();
    }
    return instance;
};

void Settings::load(){
    json_file.open(ofToDataPath("settings.json"));
}

Json::Value Settings::getData(string key){
    return Settings::json_file[key];
}

int Settings::getWidth(){
    return 192 * SCALE;
}

int Settings::getHeight(){
    return 157 * SCALE;
}

int Settings::getHeaderHeight(){
    return 32 * SCALE;
}

int Settings::getSmallHeaderPanelWidth(){
    return 36 * SCALE;
}
int Settings::getBigHeaderPanelWidth(){
    return 48 * SCALE;
}
int Settings::getHeaderPanelHeight(){
    return 16 * SCALE;
}

int Settings::getPort(){
    return Settings::getData("port").asInt();
}

string Settings::assetsPath(){
    return ofToDataPath("assets/" );
}

float Settings::getPlayerHeight(){
    return 24 * SCALE;
}

float Settings::getPlayerSeparation(){
    return 3 * SCALE;
}

float Settings::getPlayerCenterX(){
    return 8 * SCALE;
}

float Settings::getPlayerCenterY(){
    return 8 * SCALE;
}

float Settings::getPlayerOuterRadius(){
    return 5 * SCALE;
}

float Settings::getPlayerInnerRadius(){
    return 3 * SCALE;
}

float Settings::getPlayerMargin(){
    return 7 * SCALE;
}

float Settings::getTeamSeparation(){
    return 9 * SCALE;
}

int Settings::getBlockSeparation(){
    return BLOCK_SEPARATION;
}

float Settings::getTeamScoreX(int team){
    int y = getSmallHeaderPanelWidth();
    if (team == 1){
        y += getSmallHeaderPanelWidth() * 2 + getBigHeaderPanelWidth();
    }
    return y;
}
ofColor Settings::getPlayerColor(int team, int id){
    string player = "player_" + ofToString(team) + ofToString(id);
    string color = Settings::getData(player).asString();
    return ofColor::fromHex(ofHexToInt("0x" + color));
}

ofColor Settings::getColor(string colorName){
    string color = Settings::getData(colorName).asString();
    return ofColor::fromHex(ofHexToInt("0x" + color));
}

float Settings::getMoveSize(){
    return 181/(16*6);
}
string Settings::getFont(){
    return "FuturaLT-CondensedLight.ttf";
}
string Settings::getBoldFont(){
    return "FuturaLT-CondensedExtraBold.ttf";
}


int Settings::getNumberOfSongs(){
    return Settings::getData("number_of_songs").asInt();
}

string Settings::getMidiIn(){
    return Settings::getData("midi_in").asString();
}

string Settings::getMidiOut(){
    return Settings::getData("midi_out").asString();
}

int Settings::getScale(){
    return SCALE;
}
