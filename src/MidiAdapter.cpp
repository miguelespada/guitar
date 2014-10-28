//
//  MidiAdapter.cpp
//  heinneken
//
//  Created by miguel on 27/10/14.
//
//

#include "MidiAdapter.h"


MidiAdapter::MidiAdapter(){}

void MidiAdapter::open(string port){
    midiOut.listPorts();
    midiOut.openPort(port);
}

MidiAdapter::~MidiAdapter(){
    midiOut.closePort();
}

void MidiAdapter::sendNoteOn(int note){
    cout << "Midi on: " << note << endl;
    midiOut.sendNoteOn(channel, note,  64);
}

void MidiAdapter::sendNoteOff(int note){
    cout << "Midi off: " << note << endl;
    midiOut.sendNoteOff(channel, note,  64);
}