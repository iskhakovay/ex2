#include "Card.h"
#include "Player.h"
#include <iostream>
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):cardsArray(cardsArray),
                                                                                    numOfCards(numOfCards),
                                                                                    current_card(0),
                                                                                   player(playerName){
}
//
GameStatus Mtmchkin::getGameStatus() const {
    if(this->player.getLevel() == 10){
        return GameStatus::Win;
    }else if(this->player.isKnockedOut()){
        return GameStatus::Loss;
    }
    return GameStatus::MidGame;
}///

bool Mtmchkin::isOver() const {
    if(getGameStatus()!=GameStatus::MidGame){
        return true;
    }
    return false;
}
void Mtmchkin::playNextCard() {
    if(this->current_card == this->numOfCards){ // reset cards array;
        this->current_card = 0;
    }
    //------MOVE--------
    this->cardsArray[this->current_card].printInfo(); // step 1&2
    this->cardsArray[this->current_card].applyEncounter(this->player); // step 3
    this->player.printInfo();
    this->current_card++;
}