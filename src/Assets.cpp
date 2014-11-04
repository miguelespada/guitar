//
//  Assets.cpp
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#include "Assets.h"


Assets::Assets(){
    ofLogVerbose() << "Constructing Assets ";
}

Assets::~Assets(){
    ofLogVerbose() << "Destroying Assets ";
}

void Assets::load(){


    string assets_path = Settings::getInstance()->assetsPath();
    ofLogNotice() << "Loading assets from..." << assets_path;

    string filename = assets_path + "background.jpg";
    background.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;

    filename = assets_path + "intro-background.jpg";
    intro_background.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
}



