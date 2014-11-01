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
    ofDirectory dir(ofToDataPath(""));
    //only show png files
    dir.allowExt("json");
    //populate the directory object
    dir.listDir();
    
    //go through and print out all the paths
    for(int i = 0; i < dir.numFiles(); i++){
        ofLogNotice(dir.getPath(i));
    }
    
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
