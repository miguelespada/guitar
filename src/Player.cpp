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
    delete team;
    team = NULL;
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

    player_score_text.init(ofToDataPath(Settings::getInstance()->getBoldFont()), 24);
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
    inactivity_counter = 0;
    bDown = false;
    height = y_down - y_up;
}

void Player::draw(bool start){
    ofPushStyle();
    drawBackground();
    drawBlocks();

    if(start){
        if (!isInactive()){
            drawGradients();
        }
        drawIcon();

        if (!isInactive()){
            drawPlayerScore();
        }
    drawInactivityPanel();
    }




    ofPopStyle();
}
void Player::drawForStarting(){
    ofPushStyle();
    drawBackground();
    drawIcon();
    ofPopStyle();
}

void Player::drawInactivityPanel(){
    if (isInactive()){
        int width = Settings::getInstance()->getWidth();
        int height = Settings::getInstance()->getPlayerHeight();
        ofSetColor(ofColor(0,0,0,180));
        ofRect(0, 0, width, height);
    }

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
    updateBonus();
    updateInactivityCounter();
}

void Player::updateInactivityCounter(){
    inactivity_counter++;
}

bool Player::isInactive(){
    return inactivity_counter/60 > Settings::getInstance()->getInactivityTime();
}

void Player::updateBonus(){
    Settings* settings = Settings::getInstance();
    if (0 <= perfect_blocks && perfect_blocks < settings->getBonusMark(1)){
        bonus = 0;
    } else if (settings->getBonusMark(1) <= perfect_blocks && perfect_blocks < settings->getBonusMark(2)){
        bonus = 1;
    } else {
        bonus = 2;
    }
    settings = NULL;
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
    if (isInactive()){
        return false;
    }
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b){
        if (bDown == (*b)->isDown() && (*b)->isTouchingCircle())
            return true;
    }
    return false;
}

void Player::updateBlockTouchedPieces(){

    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b){
        if (isTouchingCircle() && (*b)->isTouchingEnd()){
           (*b)->setPieceTouched((*b)->pieceAtTheEnd());
        }
    }
}

void Player::drawPlayerScore(){
   if(isTouchingCircle()){

        float y = Settings::getInstance()->getPlayerCenterY();
        float x = Settings::getInstance()->getWidth();

        player_score_text.setText(getPlayerScoreToString());
        ofColor c = Settings::getInstance()->getPlayerColor(getTeam()->getId(), id);
        player_score_text.setColor(c.r,c.g,c.b,c.a);

        if(getTeam()->getId() == 1){
            x += 10;
            ofRotateY(180);
            ofTranslate(-Settings::getInstance()->getWidth() * 2, 0);
            player_score_text.drawLeft(x, y);
            ofTranslate(Settings::getInstance()->getWidth() * 2, 0);
            ofRotateY(180);
        }else{
           x -= 10;
           player_score_text.drawRight(x, y);
        }
   }
}
string Player::getPlayerScoreToString(){

    //Conversion to string

    string t;
    ostringstream temp;
    temp << "";

    if (blocks.size() > 0){
        int score = getBlockScore(getFirstBlockEnabled());
        if (score > 0){
            temp << "+" << score;
        }
    }

    t=temp.str();
    return t;

}

void Player::enterBlock(){
    if(bDown)
        MidiAdapter::getInstance()->sendNoteOn(getGlobalId());
}

void Player::exitBlock(){
    if(!bDown)
        MidiAdapter::getInstance()->sendNoteOn(getGlobalId());
}

void Player::updateBlocks(){
    if (blocks.size() > 0){
        GameBlock* block = blocks.front();
        if (block->hasPassedCircle()){
            block->setDisabled();
        }
        if (block->isOutOfMap()){
            if (!isInactive()){
                modifyScore(getBlockScore(block));
                perfect_blocks = (block->getNumberOfTouchedPieces() == block->getNumberOfPieces()) ? perfect_blocks + 1 : 0;
            }
            eraseBlock(0);
        }
        block = NULL;

    }
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b){
        (*b)->update();
    }
}

int Player::getBlockScore(GameBlock* block){
    return block->getScore() * (bonus+1);
}

void Player::eraseBlock(int position){
        GameBlock* b_delete = blocks.at(position);
        blocks.erase(blocks.begin() + position);

        delete b_delete;
        b_delete = NULL;
}

void Player::drawBlocks(){
    ofColor color = getBlockPaintingColor();
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b){
        int yy = (*b)->isDown() ? y_down : y_up;
        (*b)->draw(yy - inner_radius, color);
    }
}

ofColor Player::getBlockPaintingColor(){
    Settings* settings = Settings::getInstance();
    ofColor color;
    switch (bonus){
    case 1:
        color = settings->getColor("green");
        break;
    case 2:
        color = settings->getColor("red");
        break;
    default:
        color = settings->getPlayerColor(getTeam()->getId(), id);
    }
    settings = NULL;
    return color;
}

bool Player::hasPlace(bool position_down){
    return position_down ? queue_down == 0 : queue_up == 0;
}

void Player::addNewBlock(bool position_down, int block_pieces){
    if (hasPlace(position_down)){
        incrementQueue(position_down, block_pieces);
        blocks.push_back(new GameBlock(block_pieces, position_down));

    }
}

void Player::incrementQueue(bool position_down, int pieces){
    float piece_size = Settings::getInstance()->PIECE_SIZE;
    if (position_down){
        //queue_down += (pieces + 4 + round(ofRandom(0,4))) * piece_size;
        queue_down += 8 * piece_size;
        queue_up += pieces * piece_size;
    } else{
        queue_up += 8  * piece_size;
      //  queue_up += (pieces + 4 + round(ofRandom(0,4))) * piece_size;
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
bool Player::hasScored(){
    return last_score > 0;
}
void Player::setLastScore(int value){
    last_score = value;
}

int Player::getBonus(){
    return bonus;
}
void Player::setBonus(int value){
    bonus = value;
}
int Player::getPerfectBlocks(){
    return perfect_blocks;
}
void Player::setPerfectBlocks(int value){
    perfect_blocks = value;
}



