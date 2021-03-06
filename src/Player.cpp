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

    player_score_text.loadFont(ofToDataPath(Settings::getInstance()->getBoldFont()), 48*SCALE);
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
    if(start){
        drawBackground();
    }

    drawIcon(start);
    if(start){
        drawBlocks();
        drawInactivityPanel();
        drawGradients();
        if (!isInactive()){
            drawPlayerScore();
        }
    }




    ofPopStyle();
}

void Player::drawInactivityPanel(){
    if (isInactive()){
        int width = Settings::getInstance()->getPlayerWidth();
        int height = Settings::getInstance()->getPlayerHeight();
        ofSetColor(ofColor(0,0,0,180));
        ofRect(0, 0, width, height);
    }

}

void Player::drawBackground(){
    int width = Settings::getInstance()->getPlayerWidth();
    int height = Settings::getInstance()->getPlayerHeight();
    ofColor backgroundColor = Settings::getInstance()->getColor("gray");
    ofSetColor(backgroundColor);
    ofRect(0, 0, width, height);


}

void Player::drawGradients(){
    int width = Settings::getInstance()->getPlayerWidth();
    int height = Settings::getInstance()->getPlayerHeight();

    
    
    if(inBlock && !isInactive()){
        ofColor color =  Settings::getInstance()->getPlayerColor(team->getId(), id);
        ofSetColor(color);
        Assets::getInstance()->gradients[getGlobalId()].draw(0, 0, width/2, height);
    }

    ofColor backgroundColor = Settings::getInstance()->getColor("black");
    ofSetColor(backgroundColor);
    Assets::getInstance()->gradientBlack.draw(width/2, 0, width/2, height);

}

void Player::drawIcon(bool start){
    int y =  bDown ? y_down : y_up;

    ofPath icon;
    ofColor color = inBlock && start ? Settings::getInstance()->getColor("white") : Settings::getInstance()->getPlayerColor(team->getId(), id);
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
    if (!isInactive()){
        updateInBlock();
    }
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
        Settings* settings = Settings::getInstance();

        float stringWidth = player_score_text.stringWidth(getPlayerScoreToString());
        float stringHeight = player_score_text.stringHeight(getPlayerScoreToString());

        float y = settings->getPlayerCenterY() + stringHeight/2;
        float x = settings->getPlayerWidth() - stringWidth ;

        ofSetColor(settings->getPlayerColor(getTeam()->getId(), id));

        float margin = 27;

        if(getTeam()->getId() == 1){
            x += margin;
            ofScale(-1,1);
            ofTranslate((-x * 2) - stringWidth/2, 0);
            player_score_text.drawString(getPlayerScoreToString(), x, y);
            ofTranslate((x * 2) + stringWidth/2, 0);
            ofScale(-1,1);
        }else{
           x -= margin;
           player_score_text.drawString(getPlayerScoreToString(), x, y);
        }
        settings = NULL;
   }
}
string Player::getPlayerScoreToString(){
    string ret = "";

    if (blocks.size() > 0){
        int score = getBlockScore(getFirstBlockEnabled());
        if (score > 0){
            ret = "+" + ofToString(score);
        }
    }

  return ret;

}

void Player::enterBlock(){
    if(bDown){
        MidiAdapter::getInstance()->sendNoteOn(getGlobalId());
        bInNote = true;
    }
}

void Player::exitBlock(){
    if(bInNote){
        MidiAdapter::getInstance()->sendNoteOn(getGlobalId());
        bInNote = false;
    }
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
        (*b)->draw(yy - inner_radius, color, bonus);
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
    Settings* settings = Settings::getInstance();
    float piece_size = settings->PIECE_SIZE;
    if (position_down){
        //queue_down += (pieces + 4 + round(ofRandom(0,4))) * piece_size;
        queue_down += settings->getBlockSeparation() * piece_size;
        queue_up += pieces * piece_size;
    } else{
        queue_up += settings->getBlockSeparation() * piece_size;
      //  queue_up += (pieces + 4 + round(ofRandom(0,4))) * piece_size;
        queue_down += pieces * piece_size;
    }
    settings = NULL;
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

int Player::getPlayerScore(){
    return player_score;
}


