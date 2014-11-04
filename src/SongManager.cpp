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
    bPlaying = !bPlaying;
    
}

void SongManager::stopSong(){
    MidiAdapter::getInstance()->sendNoteOn(126);
    bPlaying = !bPlaying;
}

void SongManager::nextSong(){
    MidiAdapter::getInstance()->sendNoteOn(song + 10);
    MidiAdapter::getInstance()->sendNoteOff(song + 10);
    song = (song + 1) % Settings::getInstance()->getNumberOfSongs();
}

void SongManager::prevSong(){
    if(song > 0) {
        song --;
    }
    
}

void SongManager::setMidi(){
    MidiAdapter::getInstance()->sendNoteOn(song + 10);
}

string SongManager::toString(){
    string tmp = ofToString(song) + "/" + ofToString(Settings::getInstance()->getNumberOfSongs());
    if (bPlaying)
        return "Playing " + tmp;
    else
        return "Paused " + tmp;
        
}

string SongManager::help(){
    return "(+/-) navigate songs (*) send midi (.) play/stop song ";
}