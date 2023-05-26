#include "Card.h"
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):m_cardsArray(cardsArray),
                                                                                    m_numOfCards(numOfCards),
                                                                                    m_current_card(0),
                                                                                   m_player(playerName){
}


GameStatus Mtmchkin::getGameStatus() const {
    if(this->m_player.getLevel() == 10){
        return GameStatus::Win;
    }else if(this->m_player.isKnockedOut()){
        return GameStatus::Loss;
    }
    return GameStatus::MidGame;
}

bool Mtmchkin::isOver() const {
    if(getGameStatus()!=GameStatus::MidGame){
        return true;
    }
    return false;
}
void Mtmchkin::playNextCard() {
    if(this->m_current_card == this->m_numOfCards){
        this->m_current_card = 0;
    }
    //------MOVE--------
    this->m_cardsArray[this->m_current_card].printInfo();
    this->m_cardsArray[this->m_current_card].applyEncounter(this->m_player);
    this->m_player.printInfo();
    this->m_current_card++;
}