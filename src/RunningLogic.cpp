//
//  RunningLogic.cpp
//  heinneken
//
//  Created by miguel on 01/11/14.
//
//

#include "RunningLogic.h"

RunningLogic::RunningLogic(RunningModel* model)
{
    running_model = model;
}
RunningLogic::~RunningLogic()
{
    //dtor
}

RunningModel* RunningLogic::getRunningModel(){
    return running_model;
}

void RunningLogic::playerOn(int player){
    RunningModel* model = getRunningModel();
    Player* p = model->getPlayer(player);
    p->setActive(true);
    
}

void RunningLogic::playerOff(int player){
    getRunningModel()->getPlayer(player)->setActive(false);
}

void RunningLogic::updateBlocks(){
    for(int i = 0; i< getRunningModel()->getBlocks().size(); i++){
        getRunningModel()->updateBlock(i);
    }
}

void RunningLogic::generateBlocks(){
    RunningModel* model = getRunningModel();
    generate_player_turn = (generate_player_turn + 1)%model->getNumberOfPlayers();
    int player_number = generate_player_turn + 1;
    int block_pieces = 4 * ofRandom(1, 5);
    if (model->getPlayer(player_number)->getRemainingPieces() >= block_pieces){
        if (ofRandom(0,100) < 12){
            if (isPaintable(player_number, block_pieces)){
                model->addNewBlock(player_number, block_pieces);
            }
        }
    }
    model = NULL;
}

bool RunningLogic::isPaintable(int player, int pieces){
    Settings* settings = Settings::getInstance();
    RunningModel* model = getRunningModel();
    Player* p = model->getPlayer(player);
    
    if (p->getLastBlockId() == 0) {
        return true;
    } else{
        GameBlock b = model->getBlockById(p->getLastBlockId());
        if (b.getId() == 0) return false;
        int block_size = pieces * settings->PIECE_SIZE;
        if (b.isLeftPainted()){
            if ((b.x() + settings->BLOCK_SEPARATION + block_size + (settings->PIECE_SIZE * b.getPieces())) < settings->getBeginRight() ){
                return true;
            }
        } else {
            if (b.x() > settings->BLOCK_SEPARATION + block_size + settings->getBeginLeft()){
                return true;
            }
        }
    }
    
    return false;
    model = NULL;
    p = NULL;
    settings = NULL;
}
