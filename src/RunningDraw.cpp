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


    title_font.loadFont(Settings::getInstance()->getFont(), 25);
    final_score_font.loadFont(Settings::getInstance()->getFont(), 70);

}

RunningDraw::~RunningDraw()
{
    //dtor
}
void RunningDraw::drawLogo(){
    Settings * settings = Settings::getInstance();
    Assets::getInstance()->logo.draw(settings->getLogoX(), settings->getLogoY(), settings->getLogoWidth(), settings->getLogoHeight());
}

void RunningDraw::draw(bool start){
    Settings* s = Settings::getInstance();
    if (start){
        ofBackground(255);
        //ofTranslate(40, 40);
        ofSetColor(0);
        ofRect(0, 0, s->getWidth(), s->getHeight());

    }
       // drawHeader();
        drawTeams(start);
        drawLogo();

}
void RunningDraw::drawWinner(){
    Settings* settings = Settings::getInstance();
    ofBackground(255);

    ofSetColor(0);
    ofRect(0, 0, settings->getWidth(), settings->getHeight());
    drawHeader();
    ofPushMatrix();
    ofTranslate(0, Settings::getInstance()->getHeaderHeight());

    vector<Team*> teams = running_model->getTeams();
    std::vector<Team*>::const_iterator t;
    for(t=teams.begin(); t!=teams.end(); ++t){
        (*t)->drawWinner();
        ofTranslate(settings->getWidth(), settings->getPlayerHeight() * 2 + settings->getPlayerSeparation() *2);
        ofScale(-1, 1);
    }

    ofPopMatrix();
}

RunningModel* RunningDraw::getRunningModel(){
    return running_model;
}

void RunningDraw::drawHeader(){
    Settings* settings = Settings::getInstance();
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

void RunningDraw::drawTeams(bool start){
    Settings* s = Settings::getInstance();
    ofPushMatrix();
    ofTranslate(Settings::getInstance()->getPlayerMargin(), Settings::getInstance()->getHeaderHeight());


    vector<Team*>  teams = running_model->getTeams();
    std::vector<Team*>::const_iterator t;
    for(t=teams.begin(); t!=teams.end(); ++t){
        (*t)->draw(start);
        ofTranslate(s->getWidth() - s->getPlayerMargin()*2, 0);
        ofScale(-1, -1);
    }

    ofPopMatrix();

    drawTeamScores(start);
    ofSetColor(0);
    ofRect(s->getCentralImageX() - s->getPlayerCentralImageSeparation(), s->getHeaderHeight() , s->getCentralImageWidth() + 2 * s->getPlayerCentralImageSeparation(), s->getPlayerHeight()*2 + s->getPlayerSeparation());
    ofSetColor(255);
    drawNavigate();
    
    
    //drawTitle(s->getRunningTitle());
    //drawGrid();
    //drawGrid();
}
void RunningDraw::drawTeamScores(bool start){
    vector<Team*>  teams = running_model->getTeams();

    std::vector<Team*>::const_iterator t;
    for(t=teams.begin(); t!=teams.end(); ++t){
        (*t)->drawTeamScore(start);

    }
}

void RunningDraw::drawTitle(string title){
    Settings* settings = Settings::getInstance();
    float width = title_font.stringWidth(title);
    float title_x= settings->getWidth() / 2 - width/2;
    float title_y = settings->getTitleY();

//    if (ofGetFrameNum() % settings->getTitleRUNNINGChangeTime() == 0){
//        changeText = !changeText;
//    }

        title_font.drawString(title, title_x, title_y);
}


void RunningDraw::drawGrid(){
    ofSetColor(255,255,255);

    float compass = Settings::getInstance()->getWidth() / 4;
    float beat = compass / 4;
    float subbeat = beat / 6;
    float margin_circle = Settings::getInstance()->getPlayerCenterX() + Settings::getInstance()->getPlayerOuterRadius();
    int scale = Settings::getInstance()->getScale();

    float d = 11.3125 * scale;
    for (int i = 0; i < 16 ; i++){
        if(i%4 == 0){
            ofSetColor(255,0,0);
        }else{
            ofSetColor(255,255,255);
        }

        ofLine(i * d + margin_circle , 0, i * d  + margin_circle, Settings::getInstance()->getHeight());
    }

}
void RunningDraw::drawFinalScore(){
    Settings* settings = Settings::getInstance();
    ofSetColor(255);
    string str = ofToString(running_model->getTeams().front()->getScore());
    float x = Settings::getInstance()->getWidth() / 2 - final_score_font.stringWidth(str) / 2;
    float y = Settings::getInstance()->getPlayerHeight() * 3;
    final_score_font.drawString(str,x ,y );

    str = ofToString(running_model->getTeams().back()->getScore());
    x = Settings::getInstance()->getWidth() / 2 - final_score_font.stringWidth(str) / 2;
    y = Settings::getInstance()->getPlayerHeight() * 6 - settings->getPlayerSeparation() * 2;
    final_score_font.drawString(str,x ,y );


}
void RunningDraw::drawNavigate(){
    Settings * settings = Settings::getInstance();
    Assets::getInstance()->navigate_the_sub.draw(settings->getCentralImageX(), settings->getCentralImageY(), settings->getCentralImageWidth(), settings->getCentralImageHeight());
}
