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
}

RunningDraw::~RunningDraw()
{
    //dtor
}

void RunningDraw::draw(){
    ofBackground(255);
    ofTranslate(40, 40);
    ofSetColor(0);
    ofRect(0, 0, Settings::getInstance()->getWidth(), Settings::getInstance()->getHeight());
    drawHeader();
    drawTeams();
    drawBeatCounter();
}

RunningModel* RunningDraw::getRunningModel(){
    
    return running_model;
}

void RunningDraw::drawHeader(){
    ofSetColor(192);
    ofRect(0, 0, Settings::getInstance()->getWidth(), Settings::getInstance()->getHeaderHeight());
    
    
}

void RunningDraw::drawTeams(){
    ofPushMatrix();
    ofTranslate(0, Settings::getInstance()->getHeaderHeight());
    
    vector<Team*>  teams = running_model->getTeams();
    
    std::vector<Team*>::const_iterator t;
    for(t=teams.begin(); t!=teams.end(); ++t){
        (*t)->draw();
        ofTranslate(Settings::getInstance()->getWidth(), Settings::getInstance()->getTeamSeparation() - Settings::getInstance()->getPlayerMargin());
        ofScale(-1, 1);
    }
    ofPopMatrix();
}

void RunningDraw::drawBeatCounter(){
    int beat = getRunningModel()->getBeatCounter();
    int x = ofGetWidth() - ( beat % ofGetWidth() );
    ofLine(x, ofGetHeight(), x, ofGetHeight() - 50);
    
}