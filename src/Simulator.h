//
//  OscSimulator.h
//  heinneken
//
//  Created by miguel on 27/10/14.
//
//

#ifndef __heinneken__OscSimulator__
#define __heinneken__OscSimulator__

#include <stdio.h>
#include "ofxOsc.h"

class Simulator{
    ofxOscSender sender;
    
public:
    Simulator();
    
    void key_down();
    void playerOn(int player);
    void playerOff(int player);
    void sendMidiBeat();
    void sendMidiSubbeat();
};


#endif /* defined(__heinneken__OscSimulator__) */
