//
//  Commandable.h
//  heinneken
//
//  Created by miguel on 26/10/14.
//
//

#ifndef heinneken_Commandable_h
#define heinneken_Commandable_h

#include "ofMain.h"
#include "Action.h"

class Commandable;

class Command {
public:
    string action;
    virtual ~Command(){};
    virtual void run(Action *_action, Commandable *g) =0;
    string toString(string methodName){
       return "Registering '"+ methodName + "' action with address " + action;
    }
};

class Commandable{
    
public:
    std::vector<Command*> commands;

    void run(Action *action){
        std::vector<Command*>::const_iterator c;
        for(c=commands.begin(); c!=commands.end(); ++c)
            (*c)->run(action, this);
    }
    
    void destroyCommands(){
        std::vector<Command*>::const_iterator c;
        for(c=commands.begin(); c!=commands.end(); ++c)
            delete *c;
    }
};

#endif
