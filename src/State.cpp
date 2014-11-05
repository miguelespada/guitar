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
    Assets::getInstance()->theSub.play();


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
    
    Assets::getInstance()->theSub.draw(0, 0, ofGetWidth(), ofGetHeight());
};
void IDLE::update(){
   // gameLogic->update();
    Assets::getInstance()->theSub.update();
}
void IDLE::push()
{
    Assets::getInstance()->theSub.stop();
    game->setCurrent(new STARTING(game));
    delete this;
};


//========================================================================

STARTING::STARTING(Game *g){
    game = g;
    ofLogNotice() << "State: " << toString();
    gameLogic = new GameLogic();
    gameLogic->constructRunningServices();

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
    Assets::getInstance()->navigate_the_sub.play();

};

void RUNNING::draw(){
    Assets::getInstance()->navigate_the_sub.update();
    gameLogic->draw();

};

void RUNNING::update(){
    gameLogic->update();
}

void RUNNING::push()
{
    Assets::getInstance()->navigate_the_sub.stop();

    game->setCurrent(new FINISHING(game, gameLogic));

    game->songManager->stopSong();
};

void RUNNING::notify(Action *action){
    gameLogic->notify(action);
};

RUNNING::~RUNNING(){
    delete gameLogic;
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

void FINISHING::push()
{
    game->setCurrent(new WINNER(game, gameLogic));
};

void FINISHING::notify(Action *action){
    gameLogic->notify(action);
};

void FINISHING::jump()
{
    game->setCurrent(new MESSAGES(game));
};

//========================================================================


WINNER::WINNER(Game *g, GameLogic* gLogic){
    game = g;
    ofLogNotice() << "State: " << toString();
    gameLogic = gLogic;
    timer = ofGetElapsedTimeMillis();
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

void WINNER::push()
{
    game->setCurrent(new MESSAGES(game));
};

//========================================================================


MESSAGES::MESSAGES(Game *g){
    game = g;
    ofLogNotice() << "State: " << toString();

}

void MESSAGES::draw(){
};

void MESSAGES::push()
{
    game->setCurrent(new IDLE(game));
};

void MESSAGES::jump()
{
    game->setCurrent(new STARTING(game));
};

//========================================================================
