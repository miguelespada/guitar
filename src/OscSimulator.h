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

class OscSimulator{
    ofxOscSender sender;
    
public:
    OscSimulator();
    
    void key_down();
    void playerOn(int player);
    void playerOff(int player);
};


#endif /* defined(__heinneken__OscSimulator__) */
