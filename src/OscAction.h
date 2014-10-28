//
//  OscAction.h
//  heinneken
//
//  Created by miguel on 27/10/14.
//
//

#ifndef heinneken_OscAction_h
#define heinneken_OscAction_h

#include "Action.h"
#include "ofxOsc.h"

class OscAction: public Action
{
    ofxOscMessage m;
public:
    OscAction(ofxOscMessage _m);
    ~OscAction(){};
    
    string getAction();
    int getArgAsInt(int index);
};


#endif
