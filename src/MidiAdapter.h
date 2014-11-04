//
//  MidiAdapter.h
//  heinneken
//
//  Created by miguel on 27/10/14.
//
//

#ifndef __heinneken__MidiAdapter__
#define __heinneken__MidiAdapter__

#include "ofMain.h"
#include "ofxMidi.h"
#include "Observer.h"


class MidiAdapter: public ofxMidiListener{
    
    MidiAdapter();
    static MidiAdapter* instance;
    
    ofxMidiIn midiIn;
    int channel = 6;
    Observer *observer;
    
    int subbeats;
    int beats;
    int ticks;
    int compass;
public:
    ofxMidiOut midiOut;
    static MidiAdapter* getInstance();
    ~MidiAdapter();
    
    void newMidiMessage(ofxMidiMessage& eventArgs);
    
    void open(string input_port, string output_port);
    void sendNoteOn(int note);
    void sendNoteOff(int note);
    void registerObserver(Observer *o);
    string toString();
};

#endif /* defined(__heinneken__MidiAdapter__) */
