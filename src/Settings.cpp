//
//  Settings.cpp
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#include "Settings.h"

Settings::Settings(){
    cout << "Constructing Settings " << endl;
    
}
Settings::~Settings(){
    cout << "Destroying Settings " << endl;
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
    return Settings::getData("width").asInt();
}

int Settings::getHeight(){
    return Settings::getData("height").asInt();
}

int Settings::getPort(){
    return Settings::getData("port").asInt();
}

string Settings::assetsPath(){
    return ofToDataPath("assets/" );
}

int Settings::getPlayerHeight(){
    return getHeight() / 6;
}

int Settings::getPlayerSeparation(){
    return getHeight() / 36;
}

int Settings::getPlayerCenter(){
    return getWidth() / 30;
}

int Settings::getPlayerRadius(){
    return getPlayerCenter()/2;
}

int Settings::getPlayerMargin(){
    return getHeight() / 18;
}

ofColor Settings::getPlayerColor(int team, int id){
    // TODO get colors from file
    if(team == 0){
        if (id == 0)
            return ofColor(255, 0, 0);
        else
            return ofColor(0, 255, 0);
    }
    else{
        if (id == 0)
            return ofColor(255, 0, 255);
        else
            return ofColor(255, 255, 0);
    }
    
}