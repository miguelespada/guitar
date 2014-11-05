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


Assets* Assets::instance = 0;
Assets* Assets::getInstance(){
    if (instance == 0){
        instance = new Assets();
        instance->load();
    }
    return instance;
};


void Assets::load(){
     string assets_path = Settings::getInstance()->assetsPath();

    video.loadMovie(ofToDataPath(assets_path + "THE_SUB_3D_ORBIT.mp4"));
     loop.loadMovie(ofToDataPath(assets_path + "the_sub_loop.mov"));
     tunnel.loadMovie(ofToDataPath(assets_path + "SOLO_TUNEL3.mp4"));

    text.init(ofToDataPath(settings->getFont()), 24);

    ofLogNotice() << "Loading assets from..." << assets_path;

    string filename = assets_path + "background.jpg";
    background.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;

    filename = assets_path + "intro-background.jpg";
    intro_background.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;

    filename = assets_path + "navigate-the-sub.jpg";
    navigate_the_sub.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;

    filename = assets_path + "logo.jpg";
    logo.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
}



