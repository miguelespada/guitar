#pragma once

#include "ofMain.h"
#include "Game.h"
#include "Settings.h"
#include "Assets.h"
#include "AssetsFacade.h"
#include "OscAdapter.h"
#include "OscSimulator.h"
#include "MidiAdapter.h"

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
    Settings settings;
    Assets assets;
    AssetsFacade assetsFacade;
    OscAdapter oscAdapter;
    OscSimulator oscSimulator;
    MidiAdapter midi;
};


