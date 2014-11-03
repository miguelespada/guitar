//
//  RunningDraw.h
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#ifndef __heinneken__RunningDraw__
#define __heinneken__RunningDraw__

#include "ofMain.h"
#include "RunningModel.h"
#include "Settings.h"
#include "GameBlock.h"
#include "ofxTextSuite.h"

class RunningDraw
{
public:
    RunningDraw(){};
    RunningDraw(RunningModel* model);
    virtual ~RunningDraw();
    RunningModel* getRunningModel();
    void draw();
    void drawTeamScores(int team1, int team2);
    void drawTitle();
protected:
private:
    ofxTextBlock  myText;


// in draw:

    void drawTeams();
    void drawBeatCounter();
    void drawHeader();
    RunningModel* running_model;
    Settings* settings;
};

#endif /* defined(__heinneken__RunningDraw__) */
