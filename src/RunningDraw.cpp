//
//  RunningDraw.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "RunningDraw.h"

RunningDraw::RunningDraw(RunningModel* model){
    running_model = model;
    Settings* settings = Settings::getInstance();

    title_text.init(ofToDataPath("FuturaLT-CondensedLight.ttf"), 22);

}

RunningDraw::~RunningDraw()
{
    //dtor
}

void RunningDraw::draw(){
    ofBackground(255);
    ofTranslate(40, 40);
    ofSetColor(0);
    ofRect(0, 0, settings->getWidth(), settings->getHeight());
    drawHeader();
    drawTeams();
    drawBeatCounter();
}

RunningModel* RunningDraw::getRunningModel(){
    return running_model;
}

void RunningDraw::drawHeader(){
    ofSetColor(192);
    ofRect(0, 0, settings->getWidth(), settings->getHeaderHeight());
    ofSetColor(0);

    ofPushMatrix();
    ofTranslate(settings->getSmallHeaderPanelWidth(), 0);
    ofRect(0, settings->getHeaderPanelHeight(), settings->getSmallHeaderPanelWidth(),  settings->getHeaderPanelHeight() );
    ofTranslate(settings->getSmallHeaderPanelWidth(), 0);
    ofRect(0, 0, settings->getBigHeaderPanelWidth(), 2 * settings->getHeaderPanelHeight() );
    ofTranslate(settings->getBigHeaderPanelWidth(), 0);
    ofRect(0, settings->getHeaderPanelHeight(), settings->getSmallHeaderPanelWidth(),  settings->getHeaderPanelHeight() );
    ofPopMatrix();

}

void RunningDraw::drawTeams(){
    ofPushMatrix();
    ofTranslate(0, Settings::getInstance()->getHeaderHeight());

    vector<Team*>  teams = running_model->getTeams();

 //   string team1 =  teams.front()->getTeamScoreToString();
 //   string team2 =  teams.back()->getTeamScoreToString();

    std::vector<Team*>::const_iterator t;
    for(t=teams.begin(); t!=teams.end(); ++t){
        (*t)->draw();
        ofTranslate(settings->getWidth(), settings->getTeamSeparation() - settings->getPlayerMargin());
        ofScale(-1, 1);
        //ofRotateX(-180);
    }

    ofPopMatrix();
   drawTeamScores();
    drawTitle();
    drawGrid();
}
void RunningDraw::drawTeamScores(){
    vector<Team*>  teams = running_model->getTeams();

    std::vector<Team*>::const_iterator t;
    for(t=teams.begin(); t!=teams.end(); ++t){
        (*t)->drawTeamScore();

    }
}

void RunningDraw::drawTitle(){
    int title_pos = Settings::getInstance()->getWidth() / 2;

    ofSetLogLevel(OF_LOG_SILENT);
    title_text.setText("NAVIGATE THE SUB");
    title_text.wrapTextForceLines(2);
    title_text.setColor(255,255,255,100);
    title_text.drawCenter(title_pos, 0);
    ofSetLogLevel(OF_LOG_VERBOSE);
}
void RunningDraw::drawBeatCounter(){
    int beat = getRunningModel()->getBeatCounter();
    int x = ofGetWidth() - ( beat % ofGetWidth() );
    ofLine(x, ofGetHeight(), x, ofGetHeight() - 50);
}
void RunningDraw::drawGrid(){
    ofSetColor(255,255,255);

    float compass = Settings::getInstance()->getWidth() / 4;
    float beat = compass / 4;
    float subbeat = beat / 6;
    float margin_circle = Settings::getInstance()->getPlayerCenterX() + Settings::getInstance()->getPlayerOuterRadius();
    int scale = 3;

    float d = 11.3125 * 3;
    for (int i = 0; i < 16 ; i++){
                if(i%4 == 0){
                    ofSetColor(255,0,0);
                }else{
                    ofSetColor(255,255,255);
                }

                ofLine(i * d + margin_circle , 0, i * d  + margin_circle, Settings::getInstance()->getHeight());
    }

}
