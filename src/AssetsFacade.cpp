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

void AssetsFacade::drawText(string t){
    float x = settings->getSmallHeaderPanelWidth() * 2 + settings->getBigHeaderPanelWidth()/ 1.5;
    float y = settings->getPlayerCenterY() * 2;
    Assets::getInstance()->text.setText(t);
    Assets::getInstance()->text.setColor(255,255,255,255);
    Assets::getInstance()->text.drawCenter(x,y);
}
void AssetsFacade::updateVideo(){
    Assets::getInstance()->video.update();
}
void AssetsFacade::drawVideo(float x, float y){
    Assets::getInstance()->video.draw(x,y,ofGetWidth(), ofGetHeight());
}
void AssetsFacade::playVideo(){
    Assets::getInstance()->video.play();
}
void AssetsFacade::stopVideo(){
    Assets::getInstance()->video.stop();
}

