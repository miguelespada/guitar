//
//  AssetsFacade.cpp
//  carrousel
//
//  Created by miguel on 13/10/14.
//
//

#include "AssetsFacade.h"
#include "Assets.h"


AssetsFacade::AssetsFacade(){
    cout << "Constructing Assets Facade" << endl;
}

AssetsFacade::~AssetsFacade(){
    cout << "Destroying Assets Facade" << endl;
}

void AssetsFacade::setAssets(Assets *a){
    assets = a;
}

void AssetsFacade::setSettings(Settings *s){
    settings = s;
}

void AssetsFacade::draw_background(){
    assets->background.draw(0, 0, settings->width, settings->height);
}

