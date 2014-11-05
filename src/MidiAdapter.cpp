//
//  MidiAdapter.cpp
//  heinneken
//
//  Created by miguel on 27/10/14.
//
//

#include "MidiAdapter.h"
#include "MidiAction.h"
#include "Settings.h"


MidiAdapter::MidiAdapter(){
    
    beats = 0;
    subbeats = 0;
    ticks = 0;
    compass = 0;
}

MidiAdapter* MidiAdapter::instance = 0;
MidiAdapter* MidiAdapter::getInstance(){
    if (instance == 0){
        instance = new MidiAdapter();
    }
    return instance;
};

void MidiAdapter::open(string input_port, string output_port){
    midiOut.listPorts();
    midiOut.openPort(output_port);
    midiIn.listPorts();

    midiIn.openPort(input_port);
    midiIn.addListener(this);
    midiIn.ignoreTypes(false, false, false);

    ofLogNotice() << "Listening MIDI on " << input_port;
    ofLogNotice() << "Sending MIDI on " << output_port;
}


void MidiAdapter::sendNoteOn(int note){
        ofLogVerbose() << "Midi on: " << note;
    midiOut.sendNoteOn(channel, note,  64);
}

void MidiAdapter::sendNoteOff(int note){
    ofLogVerbose() << "Midi off: " << note;
    midiOut.sendNoteOff(channel, note,  64);
}

MidiAdapter::~MidiAdapter(){
    midiIn.closePort();
    midiOut.closePort();
}

//--------------------------------------------------------------
void MidiAdapter::newMidiMessage(ofxMidiMessage& msg) {

    if(msg.status == 250) {
        beats = 0;
        subbeats = 0;
        ticks = 0;
        compass = 0;
    }
    if(msg.status == 248){
        ticks += 1;

        MidiAction *action = new MidiAction("/subbeat", subbeats);
        observer->notify(action);
        delete(action);

        if(ticks == 6){
            
            subbeats += 1;
            ticks = 0;
            MidiAction *action = new MidiAction("/beat", beats);
            observer->notify(action);
            delete(action);
        }
        if(subbeats == 4){
            beats += 1;
            subbeats = 0;
        }
        if(beats == 4){
            beats = 0;
            compass += 1;
            if(compass == 65){
                ofLogNotice() << "End song" << endl;
                MidiAction *action = new MidiAction("/end_song", 0);
                observer->notify(action);
            }
            else{
                MidiAction *action = new MidiAction("/compass", compass);
                observer->notify(action);
            }
        }
        

    }
}


void MidiAdapter::registerObserver(Observer *o){
    observer = o;
}

string MidiAdapter::toString(){
    string ports = "[MIDI IN] " + Settings::getInstance()->getMidiIn() + "\n[MIDI OUT] " + Settings::getInstance()->getMidiOut();
    string tempo = ofToString(compass) + "." + ofToString(beats) + "." + ofToString(subbeats) + "." + ofToString(ticks);
    return ports + "\n" + tempo;
}
