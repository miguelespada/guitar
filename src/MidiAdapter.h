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
//#include "ofxMidi.h"

class MidiAdapter{
  //  ofxMidiOut midiOut;
    int channel = 6;
public:
    MidiAdapter();
    ~MidiAdapter();
    void open(string port);
    void sendNoteOn(int note);
    void sendNoteOff(int note);
};

#endif /* defined(__heinneken__MidiAdapter__) */
