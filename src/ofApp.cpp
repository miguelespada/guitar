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
    
    if(ofGetFrameNum() % 30 == 0)
        simulator.sendMidiBeat();
}

//--------------------------------------------------------------
void ofApp::draw(){
    game.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
            
        case '0' ... '9':
            midi.sendNoteOn(song);
            song = key - '0';
            midi.sendNoteOn(126);
            midi.sendNoteOn(song);
            break;
        case 'f':
            ofToggleFullscreen();
            break;
        case ' ':
            simulator.key_down();
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
            
        case 'q':
            simulator.playerOn(1);
            break;
        case 'w':
            simulator.playerOn(2);
            break;
        case 'e':
            simulator.playerOn(3);
            break;
        case 'r':
            simulator.playerOn(4);
            break;
        default:
            break;
    }
}

void ofApp::keyReleased(int key){
    
    switch (key) {
        case 'q':
            simulator.playerOff(1);
            break;
        case 'w':
            simulator.playerOff(2);
            break;
        case 'e':
            simulator.playerOff(3);
            break;
        case 'r':
            simulator.playerOff(4);
            break;
        default:
            break;
    }
}


