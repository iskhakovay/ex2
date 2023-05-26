
#include <iostream>
using std::cout;
using std::endl;
#include "Player.h"
#include "utilities.h"

//const char* LINE_DIVIDER  = "------------------------";



//____________CONSTRUCTIONS________________
Player::Player(const char* name, int maxHP , int force):m_name(name),m_level(1),m_force(DEFAULT_FORCE),
                                                                                m_maxHP(DEFAULT_MAX_HP),
                                                                                m_HP(DEFAULT_MAX_HP),m_coins(0){
    if(maxHP >= 0){
        this->m_maxHP = maxHP;
        this->m_HP = maxHP;
    }
    if(force >= 0){
        this->m_force = force;
    }

}

Player::Player(const char *name, int maxHP):m_name(name),m_level(1),m_force(DEFAULT_FORCE),m_maxHP(DEFAULT_MAX_HP),
                                                                                            m_HP(DEFAULT_MAX_HP),
                                                                                            m_coins(0) {
    if(maxHP >= 0){
        this->m_maxHP = maxHP;
        this->m_HP = maxHP;
    }
}

Player::Player(const char *name):m_name(name),m_level(1),m_force(DEFAULT_FORCE),m_maxHP(DEFAULT_MAX_HP),
                                                                                m_HP(DEFAULT_MAX_HP),m_coins(0) {}

//____________END OF CONSTRUCTIONS__________


void Player::printInfo(){
    printPlayerInfo(this->m_name, this->m_level, this->m_force, this->m_HP, this->m_coins);
}

void Player::levelUp() {
    this->m_level++;
}

int Player::getLevel() const {
    return this->m_level;
}
void Player::buff(int buff_force) {
    this->m_force+=buff_force;
}

void Player::heal(int heal_hp) {
    if(this->m_HP + heal_hp > this->m_maxHP){
        this->m_HP = this->m_maxHP;
    }else{
        this->m_HP+=heal_hp;
    }
}

void Player::damage(int damage_p) {
    if(this->m_HP - damage_p > 0){
        this->m_HP -= damage_p;
    }else{
        this->m_HP = 0;
    }
}
void Player::addCoins(int coins_am) {
    this->m_coins += coins_am;
}

bool Player::isKnockedOut() const {
    if(this->m_HP == 0){
        return true;
    }
    return false;
}
bool Player::pay(int price) {
    if(this->m_coins - price < 0){
        return false;
    }
    this->m_coins -= price;
    return true;
}

int Player::getAttackStrength() {
    return (this->m_force + this->m_level);
}



