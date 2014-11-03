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

    title_text.init("frabk.ttf", 18); //TODO: add font file

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

    ofxTextBlock team1 =  teams.front()->getTeamScoreFormatted();
    ofxTextBlock team2 =  teams.back()->getTeamScoreFormatted();

    std::vector<Team*>::const_iterator t;
    for(t=teams.begin(); t!=teams.end(); ++t){
        (*t)->draw();
        ofTranslate(settings->getWidth(), settings->getTeamSeparation() - settings->getPlayerMargin());
        ofScale(-1, 1);

    }

    ofPopMatrix();
    drawTeamScores(team1, team2);
    drawTitle();
    drawGrid();
}
void RunningDraw::drawTeamScores(ofxTextBlock t1, ofxTextBlock t2){

    int team0_x = Settings::getInstance()->getTeamScoreX(0);
    int team1_x = Settings::getInstance()->getTeamScoreX(1);

    //ofSetLogLevel(OF_LOG_SILENT);
    t1.draw(team0_x + 5, Settings::getInstance()->getHeaderHeight() / 2);
    t2.wrapTextX(ofGetWidth());
    t2.drawRight(team1_x - 5, Settings::getInstance()->getHeaderHeight() /2);
    ofSetLogLevel(OF_LOG_VERBOSE);


}
void RunningDraw::drawTitle(){
    int title_pos = Settings::getInstance()->getWidth() / 2;

    ofSetLogLevel(OF_LOG_SILENT);
    title_text.setText("NAVIGATE THE SUB");
    title_text.wrapTextForceLines(2);
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

//    float x = compass;
//    for (int i = 0; i < 4; i++){
//        ofLine(i * x + margin_circle , 0, i * x + margin_circle, Settings::getInstance()->getHeight());
//        for (int j = 0; j < 4 ; j++){
//            ofLine(i * beat + margin_circle , 0, i * beat  + margin_circle, Settings::getInstance()->getHeight());
//            for (int k = 0; k < 6 ; k++){
//                ofLine(i * subbeat + margin_circle , 0, i * subbeat  + margin_circle, Settings::getInstance()->getHeight());
//            }
//        }
//    }
}
