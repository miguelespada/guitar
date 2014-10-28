#include "ofApp.h"
#include "State.h"

ofApp::ofApp(){
    cout << "Constructing Main" << endl;
}

ofApp::~ofApp(){
    cout << "Destroying Main" << endl;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    
    ofSetWindowPosition(0, 0);
    ofHideCursor();
    
    settings.load();
    
    assets.setSettings(&settings);
    assets.load();
    
    assetsFacade.setSettings(&settings);
    assetsFacade.setAssets(&assets);
    
    oscAdapter.setSettings(&settings);
    oscAdapter.registerObserver(&game);
    oscAdapter.init();
    
    game.setSettings(&settings);
    game.setAssetsFacade(&assetsFacade);
    game.setCurrent(new IDLE(&game));
    
    midi.open("IAC Driver Bus 1");
}

//--------------------------------------------------------------
void ofApp::update(){
    oscAdapter.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    game.draw();
}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case ' ':
            oscSimulator.key_down();
            break;
        case 'j':
            game.jump();
            break;
        case 'c':
            ofHideCursor();
            break;
        case 'C':
            ofShowCursor();
            break;
        case '1':
            oscSimulator.playerOn(1);
            break;
        case '2':
            oscSimulator.playerOff(1);
            break;
        case 'n':
            midi.sendNoteOn(0);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    switch (key) {
        case 'n':
            midi.sendNoteOff(0);
            break;
        default:
            break;
    }
}


