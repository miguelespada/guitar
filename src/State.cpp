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
};

void IDLE::draw(){
    game->assetsFacade->draw_background();
};

void IDLE::push()
{
    game->setCurrent(new STARTING(game));
    delete this;
};


//========================================================================

STARTING::STARTING(Game *g){
    game = g;
    ofLogNotice() << "State: " << toString();
}

void STARTING::draw(){
    game->assetsFacade->drawIntro();
};


void STARTING::push()
{
    game->setCurrent(new RUNNING(game));
    delete this;
};


void STARTING::jump()
{
    game->setCurrent(new WINNER(game));
    delete this;
};

//========================================================================

RUNNING::RUNNING(Game *g){
    game = g;
    gameLogic = new GameLogic();
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

void RUNNING::push()
{
    game->setCurrent(new WINNER(game));
};

void RUNNING::notify(Action *action){
    gameLogic->notify(action);
};

RUNNING::~RUNNING(){
    delete gameLogic;
};

//========================================================================

WINNER::WINNER(Game *g){
    game = g;
    ofLogNotice() << "State: " << toString();

    timer = ofGetElapsedTimeMillis();
}

void WINNER::draw(){
    if((ofGetElapsedTimeMillis() - timer) > 1000){
        game->setCurrent(new IDLE(game));
        delete this;
    }
};

void WINNER::push()
{
};

//========================================================================
