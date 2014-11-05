#include "ofApp.h"
#include "State.h"
#include "Settings.h"

ofApp::ofApp(){
    ofLogVerbose() << "Constructing Main";
}

ofApp::~ofApp(){
    ofLogVerbose() << "Destroying Main";
}

//--------------------------------------------------------------
void ofApp::setup(){

    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    ofSetWindowPosition(0, 0);
    ofHideCursor();

    ofSetLogLevel(OF_LOG_NOTICE);

    assets.load();

    assetsFacade.setAssets(&assets);

    oscAdapter.registerObserver(&game);
    oscAdapter.init();

    game.setAssetsFacade(&assetsFacade);

    game.setSongManager(&songManager);
    game.setCurrent(new IDLE(&game));

    MidiAdapter::getInstance()->open(Settings::getInstance()->getMidiIn(), Settings::getInstance()->getMidiOut());
    MidiAdapter::getInstance()->registerObserver(&game);

    ofEnableAlphaBlending();
    
    ofSetWindowShape(1920 * SCALE, 1080 * SCALE);
}

//--------------------------------------------------------------
void ofApp::update(){

    oscAdapter.update();
   if (!manual_mode) game.update();

    if(bSimulate){
        simulator.sendMidiSubbeat();

        if(ofGetFrameNum() % 6 == 0)
            simulator.sendMidiBeat();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushStyle();
        ofPushMatrix();
        game.draw();
        ofPopMatrix();

    if(bInfo){
        ofSetColor(255, 0, 0);
        ofLine(ofGetMouseX(), 0, ofGetMouseX(), ofGetHeight());
        ofLine(0, ofGetMouseY(), ofGetWidth(), ofGetMouseY());
        ofDrawBitmapString(ofToString(ofGetMouseX()) + ", " + ofToString(ofGetMouseY()), ofGetMouseX() + 10, ofGetMouseY() + 10);

        ofSetColor(0);
        ofDrawBitmapString(songManager.toString() + "\n" + songManager.help(), 10, ofGetHeight() - 40);
        ofDrawBitmapString(MidiAdapter::getInstance()->toString(), 10, ofGetHeight() - 80);
    }
    ofPopStyle();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int key_player = 0;
    switch (key) {

        case '1' ... '4':
            ofLogNotice() << "[MIDI for player] " << key - '1';
            MidiAdapter::getInstance()->sendNoteOn(key - '1');
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
            key_player = 0;
            if (canDoKeyActionDebug(key_player, false)){
                simulator.playerOn(key_player);
            }
            break;
        case 'w':
            key_player = 1;
            if (canDoKeyActionDebug(key_player, false)){
                simulator.playerOn(key_player);
            }
            break;
        case 'e':
            key_player = 2;
            if (canDoKeyActionDebug(key_player, false)){
                simulator.playerOn(key_player);
            }
            break;
        case 'r':
            key_player = 3;
            if (canDoKeyActionDebug(key_player, false)){
                simulator.playerOn(key_player);
            }
            break;
        case 'x':
            game.update();
            break;
        case 'z':
            manual_mode = !manual_mode;
            break;
        case '+':
            songManager.playNextSong();
            break;
        case '-':
            songManager.prevSong();
            break;
        case '*':
            songManager.setMidiAndNext();
            break;
        case '.':
            songManager.togglePlay();
            break;
        case ',':
            songManager.stopSong();
            break;

        case 'i':
            bInfo = !bInfo;
            break;
        case 'S':
            bSimulate = !bSimulate;
            break;
        default:
            break;
    }
}

void ofApp::keyReleased(int key){
    int key_player = 0;
    switch (key) {
        case 'q':
            key_player = 0;
            if (canDoKeyActionDebug(key_player, true)){
                simulator.playerOff(key_player);
            }
            break;
        case 'w':
            key_player = 1;
            if (canDoKeyActionDebug(key_player, true)){
                simulator.playerOff(key_player);
            }
            break;
        case 'e':
            key_player = 2;
            if (canDoKeyActionDebug(key_player, true)){
                simulator.playerOff(key_player);
            }
            break;
        case 'r':
            key_player = 3;
            if (canDoKeyActionDebug(key_player, true)){
                simulator.playerOff(key_player);
            }
            break;
        default:
            break;
    }
}

//DEBUG

bool ofApp::canDoKeyActionDebug(int key, bool pressed){
    //return true;
     if (keypressed[key] == pressed){
            keypressed[key] = !keypressed[key];
            return true;
        }
    return false;
}
