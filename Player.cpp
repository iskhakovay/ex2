
#include <iostream>
using std::cout;
using std::endl;
#include <string>
#include <sstream>
#include "Player.h"
#include "utilities.h"

//const char* LINE_DIVIDER  = "------------------------";

//____________SUB FUNCTIONS________________
bool nameCheck(const char* name){
    int len_of_name = (int)strlen(name);
    for(int i = 0; i<len_of_name; i++){
        if((name[i]<'A' || name[i]>'Z') && (name[i]<'a' || name[i]>'z') ){
            return false;
        }
    }
    return true;
}

//____________END OF SUB FUNCTIONS_________

//____________CONSTRUCTIONS________________
Player::Player(const char* name, int maxHP , int force):force(DEFAULT_FORCE),coins(0),maxHP(DEFAULT_MAX_HP),HP(DEFAULT_MAX_HP),level(1){/** i guess it's default values like this */
    if(maxHP >= 0){
        this->maxHP = maxHP;
        this->HP = maxHP;
    }
    if(force >= 0){
        this->force = force;
    }

    if(!nameCheck(name)){
        cout << "Entered name is invalid: " << name<<endl;
        cout<< "------------------------" <<endl;
        return; //TODO if input always okay lol?
    }
    this->name = name;
}
Player::Player(const char *name):force(DEFAULT_FORCE),coins(0),maxHP(DEFAULT_MAX_HP),HP(DEFAULT_MAX_HP),level(1) {
    if(!nameCheck(name)){
        cout << "Entered name is invalid" << endl;
        return; //TODO if input always okay lol?
    }
    this->name = name;
}
Player::Player(const char *name, int maxHP):force(DEFAULT_FORCE),coins(0),level(1) {
    if(!nameCheck(name)){
        cout << "Entered name is invalid" << endl;
        return; //TODO if input always okay lol?
    }
    this->maxHP = maxHP;
    this->HP = maxHP;
    this->name = name;
}

//TODO deconstruction
//____________END OF CONSTRUCTIONS__________


void Player::printInfo(){
    printPlayerInfo(this->name, this->level, this->force, this->HP, this->coins);
}

void Player::levelUp() {
    this->level++;
}

int Player::getLevel() const {
    return this->level;
}
void Player::buff(int buff_force) {
    this->force+=buff_force;
}

void Player::heal(int heal_hp) {
    if(this->HP + heal_hp > this->maxHP){
        this->HP = this->maxHP;
    }else{
        this->HP+=heal_hp;
    }
}

void Player::damage(int damage_p) {
    if(this->HP - damage_p > 0){
        this->HP -= damage_p;
    }else{
        this->HP = 0;
    }
}
void Player::addCoins(int coins_am) {
    this->coins += coins_am;
}

bool Player::isKnockedOut() const {
    if(this->HP == 0){
        return true;
    }
    return false;
}
bool Player::pay(int price) {
    if(this->coins - price < 0){
        return false;
    }
    this->coins -= price;
    return true;
}

int Player::getAttackStrength() {
    return (this->force + this->level);
}



