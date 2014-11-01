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


int Settings::getPlayerY(int player, bool isUp){
    int pos = 0;
    switch(player){
        case 1: pos =  P1_Y; break;
        case 2: pos =  P2_Y; break;
        case 3: pos =  P3_Y; break;
        case 4: pos =  P4_Y; break;
    }
    if(isUp){
        return pos - 50;
        
    }else{
        return pos + 50;
    }
}

int Settings::getEndlineRight(){
    return getWidth();
}
int Settings::getBeginRight(){
    return getWidth() - getBeginLeft();
}
int Settings::getEndlineLeft(){
    return 0;
}
int Settings::getBeginLeft(){
    return -MAX_BLOCK_PIECES * PIECE_SIZE;
}


