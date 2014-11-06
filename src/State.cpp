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
    gameLogic = new GameLogic();
    gameLogic->constructRunningServices();
    Assets::getInstance()->theSub.setLoopState(OF_LOOP_NORMAL);
    Assets::getInstance()->theSub.play();


};

IDLE::IDLE(Game *g, GameLogic* gLogic){
    game = g;
    ofLogNotice() << "State: " << toString();
    changeText = false;
    gameLogic = gLogic;//new GameLogic();
    gameLogic->destroyRunningServices();
    gameLogic->constructRunningServices();
    Assets::getInstance()->theSub.setLoopState(OF_LOOP_NORMAL);
    Assets::getInstance()->theSub.play();
};

void IDLE::draw(){
    Assets::getInstance()->theSub.draw(0, 0, ofGetWidth(), ofGetHeight());
    gameLogic->getRunningDraw()->draw(false);
    ofImage i = Settings::getInstance()->getIntroImage();
    i.draw(0,0,ofGetWidth(),ofGetHeight());
};

void IDLE::notify(Action *action){
    gameLogic->notify(action);
};

void IDLE::update(){
   // gameLogic->update();
    Assets::getInstance()->theSub.update();
}

void IDLE::push(){
    Assets::getInstance()->theSub.stop();
    game->setCurrent(new STARTING(game, gameLogic));
    Assets::getInstance()->theSub.stop();
    delete this;
};


//========================================================================

STARTING::STARTING(Game *g, GameLogic* gLogic){
    game = g;
    gameLogic = gLogic;
    ofLogNotice() << "State: " << toString();
    Assets::getInstance()->tunnel.play();

    timer = ofGetElapsedTimeMillis();
}

void STARTING::draw(){

    Assets::getInstance()->tunnel.draw(0, 0, ofGetWidth(), ofGetHeight());


};
void STARTING::update(){

   Assets::getInstance()->tunnel.update();

    if(ofGetElapsedTimeMillis() - timer > 4000)
        push();

}

void STARTING::push()
{

    game->setCurrent(new RUNNING(game, gameLogic));
    Assets::getInstance()->tunnel.update();
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
    Assets::getInstance()->navigate_the_sub.setLoopState(OF_LOOP_NORMAL);
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
    Assets::getInstance()->navigate_the_sub.stop();
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
    Assets::getInstance()->clip.setLoopState(OF_LOOP_NORMAL);
    Assets::getInstance()->clip.play();
    timer = ofGetElapsedTimeMillis();
}

void FINISHING::draw(){
    Assets::getInstance()->clip.draw(0, 0, ofGetWidth(), ofGetHeight());


};
void FINISHING::update(){
    Assets::getInstance()->clip.update();

    if(ofGetElapsedTimeMillis() - timer > 2500)
        push();
}

void FINISHING::push(){
    game->setCurrent(new WINNER(game, gameLogic));
    Assets::getInstance()->tunnel.update();
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
    gameLogic->getRunningLogic()->calculateWinners();
    timer = ofGetElapsedTimeMillis();
    Assets::getInstance()->theSub.play();
}

WINNER::~WINNER(){
    //delete gameLogic;
}

void WINNER::draw(){
    ofBackground(0);
    Assets::getInstance()->theSub.draw(0,0, ofGetWidth(), ofGetHeight());
    gameLogic->getRunningDraw()->draw(false);
    gameLogic->getRunningDraw()->drawWinner();
    gameLogic->getRunningDraw()->drawTitle(Settings::getInstance()->getResultTitleImage());
    
    
    if(ofGetElapsedTimeMillis() - timer > 5000)
        push();

};

void WINNER::notify(Action *action){
    if(gameLogic != NULL)
       gameLogic->notify(action);
};
void WINNER::update(){
    Assets::getInstance()->theSub.update();
}
void WINNER::push(){
    game->setCurrent(new IDLE(game, gameLogic));
    delete this;
};

//========================================================================
