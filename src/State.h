//
//  State.h
//  Game
//
//  Created by miguel on 12/10/14.
//
//

#ifndef __game__State__
#define __game__State__

#include "ofMain.h"
#include "GameLogic.h"

//========================================================================

class Game;

class State
{
public:
    Game *game;
    virtual void push() =0;
    GameLogic* gameLogic;
    virtual void jump() {};
    virtual std::string toString() {}
    virtual void draw() {}
    virtual void update() {};
    virtual void notify(Action *action) {}


};

//========================================================================

class IDLE: public State
{
public:

    IDLE(Game *g);
    ~IDLE(){};

    void push();
    bool changeText;
    std::string toString() {
        return "Idle";
    }
    void update();
    void draw();
};

//========================================================================

class STARTING: public State
{
public:
    STARTING(Game *c);
    ~STARTING(){};

    void push();
    void jump();
    void notify(Action *action);
    void update();
    std::string toString() {
        return "Starting";
    }
    void draw();
};

//========================================================================

class RUNNING: public State
{
   // GameLogic *gameLogic;

public:
    RUNNING(Game *g, GameLogic* gLogic);
    ~RUNNING();

    void push();

    std::string toString() {
        return "Running";
    }
    void draw();
    void update();

    void notify(Action *action);

};
//========================================================================

class FINISHING: public State
{
public:
    FINISHING(Game *c, GameLogic* gLogic);
    ~FINISHING(){};

    void push();
    void jump();
    void notify(Action *action);

    std::string toString() {
        return "Finishing";
    }
    void draw();
};

//========================================================================

class WINNER: public State
{
public:
    WINNER(Game *g, GameLogic* gLogic);
    ~WINNER(){};

    float timer;
    void push();

    std::string toString() {
        return "Winner";
    }
    void draw();
};

//========================================================================

class MESSAGES: public State
{
public:
    MESSAGES(Game *c);
    ~MESSAGES(){};

    void push();
    void jump();

    std::string toString() {
        return "Messages";
    }
    void draw();
};

#endif

//========================================================================
