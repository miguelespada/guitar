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
#include "Assets.h"

class RunningDraw
{
public:
    RunningDraw(){};
    RunningDraw(RunningModel* model);
    virtual ~RunningDraw();
    RunningModel* getRunningModel();
    void draw(bool start);
    void drawTeamScores(bool start);
    void drawHeader();
    void drawWinner();

    void drawTitle();
    void drawGrid();
    void drawFinalScore();
    void drawNavigate();
protected:

private:
    ofxTextBlock  title_text;
    ofxTextBlock player_score_text;
    ofTrueTypeFont title_font;
    ofTrueTypeFont final_score_font;
    bool changeText = false;
    Assets* assets;

// in draw:

    void drawTeams(bool start);
    void drawBeatCounter();

    RunningModel* running_model;
};

#endif /* defined(__heinneken__RunningDraw__) */
