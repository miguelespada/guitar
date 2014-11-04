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
    void draw(bool start);
    void drawTeamScores();
    void drawHeader();
    void drawWinner();

    void drawTitle();
    void drawGrid();
protected:

private:
    ofxTextBlock  title_text;
    ofxTextBlock player_score_text;


// in draw:

    void drawTeams(bool start);
    void drawBeatCounter();

    RunningModel* running_model;
    Settings* settings;
};

#endif /* defined(__heinneken__RunningDraw__) */
