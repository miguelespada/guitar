//
//  SongManager.cpp
//  heinneken
//
//  Created by miguel on 04/11/14.
//
//

#include "SongManager.h"
#include "Settings.h"
#include "MidiAdapter.h"

SongManager::SongManager(){
    song = 0;
}


SongManager::~SongManager(){};


void SongManager::togglePlay(){
    if(bPlaying)
        stopSong();
    else
        playSong();
}

void SongManager::playSong(){
    
    MidiAdapter::getInstance()->sendNoteOn(125);
    MidiAdapter::getInstance()->sendNoteOn(125);
}

void SongManager::stopSong(){
    MidiAdapter::getInstance()->sendNoteOn(126);
}

void SongManager::playNextSong(){
    if(bFirstTime){
        MidiAdapter::getInstance()->sendNoteOn(0);
        bFirstTime = false;
    }
    else{
    
        MidiAdapter::getInstance()->sendNoteOn(song + 10);
        song = (song + 1) % Settings::getInstance()->getNumberOfSongs();
    }
    MidiAdapter::getInstance()->resetCompass();
    MidiAdapter::getInstance()->sendNoteOn(song + 10);
}

void SongManager::prevSong(){
    if(song > 0) {
        song --;
    }
}

void SongManager::setMidiAndNext(){
    MidiAdapter::getInstance()->sendNoteOn(song + 10);
    song = (song + 1) % Settings::getInstance()->getNumberOfSongs();
}

string SongManager::toString(){
    string tmp = ofToString(song) + "/" + ofToString(Settings::getInstance()->getNumberOfSongs());
    return tmp;
        
}

string SongManager::help(){
    return "(.) Play current solo (+) Solo next song (*) send midi and inc (-) dec song (,) stop playing ";
}