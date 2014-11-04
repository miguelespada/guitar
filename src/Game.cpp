//
//  Game.cpp
//  Game
//
//  Created by miguel on 12/10/14.
//
//

#include "Game.h"
#include "Command.h"

Game::Game(){
    commands.push_back(new Next("/key_down"));
    commands.push_back(new EndSong("/end_song"));
}

Game::~Game(){
    destroyCommands();
}

void Game::notify(Action *action){
    // Chain of command
    current_state->notify(action);    
    run(action);
}

void Game::setCurrent(State *s)
{
    current_state = s;
}

void Game::setAssetsFacade(AssetsFacade *a)
{
    assetsFacade = a;
}

void Game::setSongManager(SongManager *s){
    songManager = s;
}

void Game::next()
{
    current_state->push();
}

void Game::jump()
{
    current_state->jump();
}

void Game::draw()
{
    current_state->draw();
}

void Game::update()
{
    current_state->update();
}


