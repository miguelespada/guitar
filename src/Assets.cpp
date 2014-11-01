//
//  Assets.cpp
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#include "Assets.h"


Assets::Assets(){
    cout << "Constructing Assets " << endl;
}

Assets::~Assets(){
    cout << "Destroying Assets " << endl;
}

void Assets::load(){
    
    
    string assets_path = Settings::getInstance()->assetsPath();
    cout << "Loading assets from..." << assets_path << endl;
    
    string filename = assets_path + "background.jpg";
    background.loadImage(filename);
    cout << "Loading: " << filename << endl;
}



