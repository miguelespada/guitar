//
//  State.cpp
//  Game
//
//  Created by miguel on 12/10/14.
//
//

#include "State.h"
#include "Game.h"
#include "AssetsFacade.h"

//========================================================================

IDLE::IDLE(Game *g){
    game = g;
    ofLogNotice() << "State: " << toString();
    changeText = false;
    game->assetsFacade->playVideo();
    gameLogic = new GameLogic();
    gameLogic->constructRunningServices();

};

IDLE::IDLE(Game *g, GameLogic* gLogic){
    game = g;
    ofLogNotice() << "State: " << toString();
    changeText = false;
    game->assetsFacade->playVideo();
    gameLogic = gLogic;//new GameLogic();
    gameLogic->destroyRunningServices();
    gameLogic->constructRunningServices();

};

void IDLE::draw(){
//    ofBackground(255);
//    ofSetColor(255,255,255,255);
//    game->assetsFacade->drawIntro();
//    if (ofGetFrameNum() % Settings::getInstance()->getTitleIDLEChangeTime() == 0){
//        changeText = !changeText;
//    }
//
//    if(changeText){
//        game->assetsFacade->drawText("HOLA CAPITANES");
//    }else{
//        game->assetsFacade->drawText("COMIENZA LA INMERSIÓN");
//    }
    game->assetsFacade->drawVideo(0,0);
};
void IDLE::update(){
   // gameLogic->update();
   game->assetsFacade->updateVideo();
}
void IDLE::push()
{   game->assetsFacade->stopVideo();
    game->setCurrent(new STARTING(game, gameLogic));
    delete this;
};


//========================================================================

STARTING::STARTING(Game *g, GameLogic* gLogic){
    game = g;
    gameLogic = gLogic;
    ofLogNotice() << "State: " << toString();

}

void STARTING::draw(){

    ofSetColor(0);
    ofRect(0, 0, Settings::getInstance()->getWidth(), Settings::getInstance()->getHeight());
    //gameLogic->getRunningDraw()->draw(false);

};

void STARTING::push()
{
    game->setCurrent(new RUNNING(game, gameLogic));
    delete this;
};

void STARTING::notify(Action *action){
    gameLogic->notify(action);
};


void STARTING::jump()
{
    game->setCurrent(new WINNER(game, gameLogic));
    delete this;
};

//========================================================================

RUNNING::RUNNING(Game *g, GameLogic* gLogic){
    game = g;
    gameLogic = gLogic;
    ofLogNotice() << "State: " << toString();
    game->songManager->playNextSong();
    game->songManager->playSong();

};

void RUNNING::draw(){
    gameLogic->draw();

};

void RUNNING::update(){
    gameLogic->update();
}

void RUNNING::push(){
    game->setCurrent(new FINISHING(game, gameLogic));
    game->songManager->stopSong();
    delete this;
};

void RUNNING::notify(Action *action){
    gameLogic->notify(action);
};

RUNNING::~RUNNING(){
};

//========================================================================
FINISHING::FINISHING(Game *g, GameLogic* gLogic){
    game = g;
    ofLogNotice() << "State: " << toString();
    gameLogic = gLogic;
}

void FINISHING::draw(){
    ofBackground(255);
    ofSetColor(0);
    ofRect(0, 0, Settings::getInstance()->getWidth(), Settings::getInstance()->getHeight());

};

void FINISHING::push(){
    game->setCurrent(new WINNER(game, gameLogic));
    delete this;
};

void FINISHING::notify(Action *action){
    gameLogic->notify(action);
};

void FINISHING::jump()
{
};

//========================================================================


WINNER::WINNER(Game *g, GameLogic* gLogic){
    game = g;
    ofLogNotice() << "State: " << toString();
    gameLogic = gLogic;
    timer = ofGetElapsedTimeMillis();
}

WINNER::~WINNER(){
    //delete gameLogic;
}

void WINNER::draw(){
    ofBackground(255);
    ofSetColor(0);
    ofRect(0, 0, Settings::getInstance()->getWidth(), Settings::getInstance()->getHeight());
    gameLogic->getRunningDraw()->draw(false);
  //  gameLogic->getRunningDraw()->drawWinner();
  //  gameLogic->getRunningDraw()->drawFinalScore();
};

void WINNER::notify(Action *action){
    gameLogic->notify(action);
};

void WINNER::push(){
    game->setCurrent(new IDLE(game, gameLogic));
    delete this;
};

//========================================================================
