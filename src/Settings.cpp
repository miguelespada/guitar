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
    return 1920 * SCALE;
}

int Settings::getHeight(){
    return 1080 * SCALE;
}

int Settings::getHeaderHeight(){
    return getHeight()/2 - getPlayerHeight() - getPlayerSeparation()/2 * SCALE;
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
    return 200 * SCALE;
}

float Settings::getPlayerSeparation(){
    return 20 * SCALE;
}

float Settings::getPlayerCenterX(){
    return 55 * SCALE;
}

float Settings::getPlayerCenterY(){
    return 100 * SCALE;
}

float Settings::getPlayerOuterRadius(){
    return 55/2 * SCALE;
}

float Settings::getPlayerInnerRadius(){
    return 35/2 * SCALE;
}

float Settings::getPlayerMargin(){
    return 70 * SCALE;
}

float Settings::getTeamSeparation(){
    return 9 * SCALE;
}

int Settings::getBlockSeparation(){
    return BLOCK_SEPARATION * 2;
}

float Settings::getTeamScoreX(int team){
    int y = getPlayerMargin() + getPlayerWidth()/2;
    if (team == 1){
        y = getWidth() - y;
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
    return getPlayerWidth()/(16*6);
}
string Settings::getFont(){
    return ofToDataPath("FuturaLT-CondensedLight.ttf");
}
string Settings::getBoldFont(){
    return ofToDataPath("FuturaLT-CondensedExtraBold.ttf");
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

float Settings::getSpeed(){
    return speed;
}

void Settings::setSpeed(float _speed){
    speed = _speed;

}
int Settings::getBonusMark(int bonus){
    switch (bonus){
    case 1:
        return 10;
        break;
    case 2:
        return 20;
        break;
    }
}

int Settings::getInactivityTime(){
    return 10;
}

int Settings::getTitleRUNNINGChangeTime(){
    return 60 * 2;
}

int Settings::getTitleIDLEChangeTime(){
    return 60 * 6;
}
float Settings::getPlayerWidth(){
    return PLAYER_WIDTH;
}
float Settings::getCentralImageX(){
    return (getPlayerMargin() + getPlayerWidth() + getPlayerCentralImageSeparation());

}
float Settings::getCentralImageY(){
        return getHeaderHeight() + 39 * SCALE;
}
float Settings::getPlayerCentralImageSeparation(){
    return 65 * SCALE;
}
float Settings::getCentralImageHeight(){
    return 342 * SCALE;
}
float Settings::getCentralImageWidth(){
    return 450 * SCALE;
}
float Settings::getTitleY(){
    return   120 * SCALE;
}
string Settings::getRunningTitle(){
    return "¡VAMOS, ATRÉVETE Y DEMUESTRA QUE ERES UN AUTÉNTICO CAPITÁN!";
}
float Settings::getLogoX(){
    return getWidth() / 2 - getLogoWidth() /2;
}
float Settings::getLogoY(){
    return getHeaderHeight() + getPlayerHeight() *2 + getPlayerSeparation() + 75 * SCALE;
}
float Settings::getLogoWidth(){
    return 200 * SCALE;
}
float Settings::getLogoHeight(){
    return 150 * SCALE;
}

ofImage Settings::getIntroImage(){
    string assets_path = assetsPath();
    ofImage img;
    img.loadImage(ofToDataPath(assets_path + "glows/"+ "intro.png"));
    return img;
}
ofImage Settings::getResultTitleImage(){
    string assets_path = assetsPath();
    ofImage img;
    img.loadImage(ofToDataPath(assets_path + "glows/"+ "resultados1.png"));
    return img;
}
ofImage Settings::getTitleImage(bool mayday){
    string filename;
    if(mayday){
        filename = "juego3.png";
    }else{
        filename = "juego1.png";
    }
    string assets_path = assetsPath();
    ofImage img;
    img.loadImage(ofToDataPath(assets_path + "glows/"+ filename));
    return img;
}
ofImage Settings::getRandomPhrase(bool winner){
    int i = round(ofRandom(1,10));
    string s = winner ? "winner" : "loser";
    string filename = s + ofToString(i);
    ofImage img;
    img.loadImage(ofToDataPath(assetsPath() + "glows/" + filename + ".png"));

    return img;

}
float Settings::getTeamScoreY(){
    return getHeaderHeight() + getPlayerHeight()*2 + getPlayerSeparation() + 120 * SCALE;
}


