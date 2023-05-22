#include <functional>
#include <string>
#include <iostream>
#include "Player.h"

int main(){
    Player player1("Efrat90",150,2);  //Efrat has 150 max HP and 2 points of force.
    Player player2("Gandalf",300);  //Gandalf has 300 max HP and 5 points of force.
    Player player3("Daniel"); //Gandalf has 100 max HP and 5 points of force.
    player2.printInfo();
    Player player4 = player3;
    player2.addCoins(10);
    if (player1.pay(10)){
        std::cout<<"paid"<<std::endl;
    }
    player3.heal(10);
    player4.damage(10);
    player2.levelUp();
    player2.buff(1);
    player2.printInfo();
    if (player2.getAttackStrength() != 2 + 6 ){
        std::cout<<"idk"<<std::endl;
    }
    if (player2.isKnockedOut()){
        std::cout << "Player is dead";
    }
    if (player2.getLevel() != 2){
        std::cout<<"we are here"<<std::endl;
    }
    player1.printInfo();
    player2.printInfo();
    return  0;
}