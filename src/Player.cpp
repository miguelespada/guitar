//
//  Player.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "Player.h"
#include "MidiAdapter.h"


Player::Player(){
    //ctor
}

Player::Player(int id, Team* team){
    Player::id = id;
    Player::team = team;
    inBlock = false;
    x = Settings::getInstance()->getPlayerCenterX();
    int y = Settings::getInstance()->getPlayerHeight()/2;
    outer_radius = Settings::getInstance()->getPlayerOuterRadius();
    inner_radius = Settings::getInstance()->getPlayerInnerRadius();
    y_up = y - Settings::getInstance()->getPlayerCenterY()/2;
    y_down = y + Settings::getInstance()->getPlayerCenterY()/2;
    queue_down = 0;
    queue_up = 0;

    player_score_text.init(ofToDataPath("FuturaLT-CondensedExtraBold.ttf"), 24);
}

Player::~Player(){
    //dtor
}

int Player::getId(){
    return id;
}


int Player::getGlobalId(){
    return team->getId() * 2 + id;
}

Team* Player::getTeam(){
    return team;
}

void Player::setOn(){
    bDown = true;
    height = y_up - y_down;
}

void Player::setOff(){
    bDown = false;
    height = y_down - y_up;
}

void Player::draw(){
    ofPushStyle();
    drawBackground();
    drawBlocks();
    drawGradients();
    drawIcon();

    drawPlayerScore();

    ofPopStyle();
}

void Player::drawBackground(){
    int width = Settings::getInstance()->getWidth();
    int height = Settings::getInstance()->getPlayerHeight();
    ofColor backgroundColor = Settings::getInstance()->getColor("gray");
    ofSetColor(backgroundColor);
    ofRect(0, 0, width, height);


}

void Player::drawGradients(){
    int width = Settings::getInstance()->getWidth();
    int height = Settings::getInstance()->getPlayerHeight();

    if(inBlock){
        ofColor color =  Settings::getInstance()->getPlayerColor(team->getId(), id);
        for(int i = 0; i < width/2; i ++){
            ofSetColor(color, ofMap(i, 0, width/2, 255, 0));
            ofLine(i, 0, i, height);
        }
    }

    ofColor backgroundColor = Settings::getInstance()->getColor("black");
    for(int i = width/2; i < width; i ++){
        ofSetColor(backgroundColor, ofMap(i, width/2, width, 0, 255));
        ofLine(i, 0, i, height);
    }

}

void Player::drawIcon(){
    int y =  bDown ? y_down : y_up;

    ofPath icon;
    ofColor color = inBlock ? Settings::getInstance()->getColor("white") : Settings::getInstance()->getPlayerColor(team->getId(), id);
    icon.setFillColor(color);

    //upper cap
    int yy = (height < 0) ? y + height + 1 : y;
    icon.arc(x, yy, inner_radius, inner_radius, 180, 360);
    icon.close();
    icon.arc(x, yy, outer_radius, outer_radius, 180, 360);
    icon.draw();
    icon.clear();

    //lower cap
    yy = (height > 0) ? y + height - 1 : y;

    icon.arc(x, yy, inner_radius, inner_radius, 0, 180);
    icon.close();
    icon.arc(x, yy, outer_radius, outer_radius, 0, 180);
    icon.draw();
    icon.clear();

    //side lines
    icon.rectangle(x + inner_radius, y, outer_radius - inner_radius, height);
    icon.rectangle(x - inner_radius, y, -outer_radius + inner_radius, height);
    icon.draw();

    height *= 0.9;
    if(abs(height) < 1) height = 0;
}

void Player::update(){
    updateInBlock();
    updateBlocks();
}


void Player::updateInBlock(){
    bool prevInBlock = inBlock;
    inBlock = getInBlock();
    updateBlockTouchedPieces();

    if(prevInBlock && !inBlock)
        exitBlock();

    if(!prevInBlock && inBlock)
        enterBlock();
}


bool Player::getInBlock(){
    return isTouchingCircle();
}

bool Player::isTouchingCircle(){
    GameBlock* b = getFirstBlockEnabled();
    if (b != NULL){
        return bDown == b->isDown() && b->isTouchingCircle();
    }
    return false;
}


void Player::updateBlockTouchedPieces(){
    GameBlock* b = getFirstBlockEnabled();
    if (b != NULL){
        if (isTouchingCircle() && b->isTouchingEnd()){
            b->setPieceTouched(b->pieceAtTheEnd());
        }
    }
}

void Player::drawPlayerScore(){
   if(isTouchingCircle()){
        float y = Settings::getInstance()->getPlayerCenterY();
        float x = Settings::getInstance()->getWidth() - 50;
        ofSetLogLevel(OF_LOG_SILENT);

        player_score_text.setText(getPlayerScoreToString());
        ofColor c = Settings::getInstance()->getPlayerColor(getTeam()->getId(), id);
        player_score_text.setColor(c.r,c.g,c.b,c.a);
        //player_score_text.setColor(255,255,255,255);
        player_score_text.drawLeft(x, y);
        ofSetLogLevel(OF_LOG_VERBOSE);
        //has_scored = 0;
   }
}
string Player::getPlayerScoreToString(){

    //Conversion to string

    string t;
    ostringstream temp;
    temp << "+" << getFirstBlockEnabled()->getScore();
    t=temp.str();
    return t;

}

void Player::enterBlock(){
   // ofLogVerbose() << "[Player] enter block ";
    MidiAdapter::getInstance()->sendNoteOn(getGlobalId());
}

void Player::exitBlock(){
   // ofLogVerbose() << "[Player] exit block ";
    MidiAdapter::getInstance()->sendNoteOff(getGlobalId());
}

void Player::updateBlocks(){
    if (blocks.size() > 0){
        if (blocks.front()->isOutOfMap()){
            modifyScore(blocks.front()->getScore());
            eraseBlock(0);
        }
        if (blocks.front()->hasPassedCircle()){
            blocks.front()->setDisabled();
        }
    }
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b){
        (*b)->update();
    }
}

void Player::eraseBlock(int position){
        GameBlock* b_delete = blocks.at(position);
        blocks.erase(blocks.begin() + position);

        delete b_delete;
        b_delete = NULL;
}

void Player::drawBlocks(){
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b){
        int yy = (*b)->isDown() ? y_down : y_up;
        (*b)->draw(yy - inner_radius);
    }
}

bool Player::hasPlace(bool position_down){
    return position_down ? queue_down == 0 : queue_up == 0;
}

void Player::addNewBlock(bool position_down, int block_pieces, ofColor color){
    if (hasPlace(position_down)){
        incrementQueue(position_down, block_pieces);
        blocks.push_back(new GameBlock(block_pieces, position_down, color));
    }
}

void Player::incrementQueue(bool position_down, int pieces){
    float piece_size = Settings::getInstance()->PIECE_SIZE;
    if (position_down){
        queue_down += (pieces + 4 + round(ofRandom(0,4))) * piece_size;
        queue_up += pieces * piece_size;
    } else{
        queue_up += (pieces + 4 + round(ofRandom(0,4))) * piece_size;
        queue_down += pieces * piece_size;
    }
}

void Player::decrementQueues(){
    if (queue_down > 0) queue_down--;
    if (queue_up > 0) queue_up--;
}

void Player::modifyScore(int value){
    player_score += value;
    last_score = value;
    team->modifyScore(value);
}

GameBlock* Player::getFirstBlockEnabled(){
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b){
        if ((*b)->isEnabled()){
            return (*b);
        }
    }
    return NULL;
}
bool Player::hasScored()
{
    return last_score > 0;
}
void Player::setLastScore(int value){
    last_score = value;
}


