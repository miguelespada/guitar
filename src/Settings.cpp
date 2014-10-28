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

void Settings::load(){
    settings.open(ofToDataPath("settings.json"));
    
    width = settings["width"].asInt();
    height = settings["height"].asInt();
    port = settings["port"].asInt();
}


string Settings::assetsPath(){
    return ofToDataPath("assets/" );
}