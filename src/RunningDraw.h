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
#include "Assets.h"

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

    void drawTitle(string title);
    void drawGrid();
    void drawNavigate();
    void drawLogo();
protected:

private:

    ofTrueTypeFont title_font;
    ofTrueTypeFont final_score_font;
    bool changeText = false;
// in draw:

    void drawTeams(bool start);
    void drawBeatCounter();

    RunningModel* running_model;
};

#endif /* defined(__heinneken__RunningDraw__) */
