#include "ofApp.h"
#include "State.h"
#include "Settings.h"

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

    assets.load();
    
    assetsFacade.setAssets(&assets);
    
    oscAdapter.registerObserver(&game);
    oscAdapter.init();
    
    game.setAssetsFacade(&assetsFacade);
    game.setCurrent(new IDLE(&game));
    
    midi.open("Network", "Network");
    midi.registerObserver(&game);
    
    int width = Settings::getInstance()->getWidth();
    int height = Settings::getInstance()->getHeight();
    
    
    ofSetWindowShape(width, height);
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
    if(key >= '0' && key <= '9'){
        midi.sendNoteOn(song);
        song = key - '0';
        midi.sendNoteOn(126);
        midi.sendNoteOn(song);
    }
    
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
        case 'z':
            oscSimulator.playerOn(1);
            break;
        case 'x':
            oscSimulator.playerOff(1);
            break;
        case 's':
            midi.sendNoteOn(127);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}


