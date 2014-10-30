//
//  MidiAdapter.cpp
//  heinneken
//
//  Created by miguel on 27/10/14.
//
//

#include "MidiAdapter.h"
#include "MidiAction.h"


MidiAdapter::MidiAdapter(){}

void MidiAdapter::open(string input_port, string output_port){
    midiOut.listPorts();
    midiOut.openPort(output_port);
    midiIn.listPorts();
    midiIn.openPort(input_port);
    midiIn.addListener(this);
    midiIn.ignoreTypes(false, false, false);
}


void MidiAdapter::sendNoteOn(int note){
    cout << "Midi on: " << note << endl;
    midiOut.sendNoteOn(channel, note,  64);
}

void MidiAdapter::sendNoteOff(int note){
    cout << "Midi off: " << note << endl;
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
        if(ticks == 6){
            
            subbeats += 1;
            ticks = 0;
            MidiAction *action = new MidiAction("/beat", subbeats);
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
        }
        
    }
}


void MidiAdapter::registerObserver(Observer *o){
    observer = o;
}