#pragma once

#include "ofMain.h"
#include "Game.h"
#include "Assets.h"
#include "AssetsFacade.h"
#include "OscAdapter.h"
#include "Simulator.h"
#include "MidiAdapter.h"
#include "SongManager.h"

class ofApp : public ofBaseApp{
public:
    ~ofApp();
    ofApp();

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);

    bool bInfo = false;

    Game game;
    Assets assets;
    AssetsFacade assetsFacade;
    OscAdapter oscAdapter;
    Simulator simulator;
    SongManager *songManager;
    
    int song = 0;

    //DEBUG
    bool keypressed[4] = { false, false, false, false };
    bool manual_mode = false;
    bool canDoKeyActionDebug(int key, bool pressed);
};


