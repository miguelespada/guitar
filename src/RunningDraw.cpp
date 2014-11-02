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
    myfont.loadFont("arial.ttf", 18);
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

    std::vector<Team*>::const_iterator t;
    for(t=teams.begin(); t!=teams.end(); ++t){
        (*t)->draw();
        ofTranslate(settings->getWidth(), settings->getTeamSeparation() - settings->getPlayerMargin());
        ofScale(-1, 1);
    }

    ofPopMatrix();
    drawTeamScores(running_model->getTeams().at(0)->getScore(), running_model->getTeams().at(1)->getScore());
    drawTitle();
}
void RunningDraw::drawTeamScores(int team1, int team2){

    //Conversion to string
    string t1, t2;
    ostringstream temp1, temp2;
    temp1 << team1;
    t1=temp1.str();
    temp2 << team2;
    t2=temp2.str();

    int team0_x = Settings::getInstance()->getTeamScoreX(0);
    int team1_x = Settings::getInstance()->getTeamScoreX(1);

    ofSetColor(255,255,255);
    myfont.drawString(t1, team0_x + 5, Settings::getInstance()->getHeaderHeight());
    myfont.drawString(t2, team1_x - 20, Settings::getInstance()->getHeaderHeight());
    //TODO: move to settings all margins
}
void RunningDraw::drawTitle(){
    int title_pos = Settings::getInstance()->getSmallHeaderPanelWidth() *2 + 10;
    ofSetColor(255,255,255);

    myfont.drawString("NAVIGATE\nTHE SUB",  title_pos, 25);
    //TODO: move to settings top margin
}
void RunningDraw::drawBeatCounter(){
    int beat = getRunningModel()->getBeatCounter();
    int x = ofGetWidth() - ( beat % ofGetWidth() );
    ofLine(x, ofGetHeight(), x, ofGetHeight() - 50);
}
