//
//  Player.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "Player.h"
#include "MidiAdapter.h"

#define DEBUG true

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
    drawIcon();
    drawBlocks();

    ofPopStyle();
}

void Player::drawBackground(){
    ofColor background = Settings::getInstance()->PLAYER_BACKGROUND;
    int width = Settings::getInstance()->getWidth();
    int height = Settings::getInstance()->getPlayerHeight();

    ofSetColor(background);
    ofRect(0, 0, width, height);
}

void Player::drawIcon(){
    int y =  bDown ? y_down : y_up;

    // TODO: color should go to constructor
    color = Settings::getInstance()->getPlayerColor(team->getId(), id);

    ofPath icon;
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
}

void Player::update(){
    updateInBlock();
    updateBlocks();
}



void Player::updateInBlock(){
    bool prevInBlock = inBlock;
    inBlock = getInBlock();

    if(prevInBlock && !inBlock)
        exitBlock();

    if(!prevInBlock && inBlock)
        enterBlock();
}

bool Player::getInBlock(){
    if (blocks.size() > 0){
        GameBlock* first_block = blocks.front();
        int piece_touching = first_block->pieceAtTheEnd() ;
        if (piece_touching != -1 && bDown == first_block->isDown()){
            if (first_block->getPieceOn() == -1){
                first_block->setPieceOn(piece_touching);
            }
            return true;
        } else{
             if (first_block->getPieceOn() != -1 && first_block->getPieceOff() == -1){
                first_block->setPieceOff(piece_touching);
                modifyScore(first_block->getScore());
            }
        }
    }
    if(DEBUG){
        return bDown;
    }

    return false;
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
                GameBlock* b_delete = blocks.front();
                blocks.erase(blocks.begin());

                delete b_delete;
                b_delete = NULL;
            }
    }
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b){
        (*b)->update();
    }
    decrementQueues();
}

void Player::drawBlocks(){
    std::vector<GameBlock*>::const_iterator b;
    for(b=blocks.begin(); b!=blocks.end(); ++b){
        int yy = (*b)->isDown() ? y_down : y_up ;
        (*b)->draw(yy - inner_radius);
    }
}

bool Player::hasPlace(bool position_down){
    return position_down ? queue_down == 0 : queue_up == 0;
}

void Player::addNewBlock(bool position_down, int block_pieces){
    Settings* settings = Settings::getInstance();
    int margin = settings->getBlockSeparation();
    int block_margin = (margin + block_pieces) * settings->PIECE_SIZE;
    if (hasPlace(position_down)){
        incrementQueue(position_down, block_margin);
        blocks.push_back(new GameBlock(block_pieces, position_down, ofColor(255,0,255)));
    }
    settings = NULL;
}

void Player::incrementQueue(bool position_down, int block_pieces){
    if (position_down){
        queue_down += block_pieces;
    } else{
        queue_up += block_pieces;
    }
}

void Player::decrementQueues(){
    if (queue_down > 0) queue_down--;
    if (queue_up > 0) queue_up--;
}



