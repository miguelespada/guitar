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

     tunnel.loadMovie(ofToDataPath(assets_path + "SOLO_TUNEL3.mp4"));

     theSub.loadMovie(ofToDataPath(assets_path + "THE_SUB_3D_ORBIT.mp4"));
     clip.loadMovie(ofToDataPath(assets_path + "CLIP_SUELTO_NEON_VERDE.mp4"));
    navigate_the_sub.loadMovie(ofToDataPath(assets_path + "the_sub_loop.mov"));


    ofLogNotice() << "Loading assets from..." << assets_path;

    string filename = assets_path + "background.jpg";
    background.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;

    filename = assets_path + "intro-background.jpg";
    intro_background.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;


    filename = assets_path + "logo.jpg";
    logo.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;

    filename = assets_path + "star.png";
    star.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
}



