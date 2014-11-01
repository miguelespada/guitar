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
}

void Game::notify(Action *action){
    // Chain of command
    current->notify(action);    
    run(action);
}

void Game::setCurrent(State *s)
{
    current = s;
}

void Game::setAssetsFacade(AssetsFacade *a)
{
    assetsFacade = a;
}

void Game::next()
{
    current->push();
}

void Game::jump()
{
    current->jump();
}

void Game::draw()
{
    current->draw();
}

