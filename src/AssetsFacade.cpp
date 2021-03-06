//
//  AssetsFacade.cpp
//  carrousel
//
//  Created by miguel on 13/10/14.
//
//

#include "AssetsFacade.h"
#include "Assets.h"
#include "Settings.h"


AssetsFacade::AssetsFacade(){
    ofLogVerbose() << "Constructing Assets Facade";
}

AssetsFacade::~AssetsFacade(){
     ofLogVerbose() << "Destroying Assets Facade";
}

void AssetsFacade::draw_background(){
    Settings * settings = Settings::getInstance();
    Assets::getInstance()->background.draw(0, 0, settings->getWidth(), settings->getHeight());
}
void AssetsFacade::drawIntro(){
    Settings * settings = Settings::getInstance();
   Assets::getInstance()->intro_background.draw(0, 0, settings->getWidth(), settings->getHeight());

}


