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
    ofSetFrameRate(60);
    
    ofSetWindowPosition(0, 0);
    ofHideCursor();

    assets.load();
    
    assetsFacade.setAssets(&assets);
    
    oscAdapter.registerObserver(&game);
    oscAdapter.init();
    
    game.setAssetsFacade(&assetsFacade);
    game.setCurrent(new RUNNING(&game));
    
    MidiAdapter::getInstance()->open("IAC Driver Bus 1", "Network");
    MidiAdapter::getInstance()->registerObserver(&game);
    
    ofEnableAlphaBlending();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    oscAdapter.update();
    game.update();
    
    if(ofGetFrameNum() % 8 == 0)
        simulator.sendMidiBeat();
}

//--------------------------------------------------------------
void ofApp::draw(){
    game.draw();
    ofSetColor(255, 0, 0);
    ofLine(ofGetMouseX(), 0, ofGetMouseX(), ofGetHeight());
    ofLine(0, ofGetMouseY(), ofGetWidth(), ofGetMouseY());
    ofDrawBitmapString(ofToString(ofGetMouseX()) + ", " + ofToString(ofGetMouseY()), ofGetMouseX() + 10, ofGetMouseY() + 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
            
        case '0' ... '9':
            MidiAdapter::getInstance()->sendNoteOn(song);
            song = key - '0';
            MidiAdapter::getInstance()->sendNoteOn(126);
            MidiAdapter::getInstance()->sendNoteOn(song);
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
            simulator.playerOn(0);
            break;
        case 'w':
            simulator.playerOn(1);
            break;
        case 'e':
            simulator.playerOn(2);
            break;
        case 'r':
            simulator.playerOn(3);
            break;
        default:
            break;
    }
}

void ofApp::keyReleased(int key){
    
    switch (key) {
        case 'q':
            simulator.playerOff(0);
            break;
        case 'w':
            simulator.playerOff(1);
            break;
        case 'e':
            simulator.playerOff(2);
            break;
        case 'r':
            simulator.playerOff(3);
            break;
        default:
            break;
    }
}


