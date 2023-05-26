
#include <functional>
#include <string>
#include <iostream>
#include "Player.h"
#include "Card.h"
#include "Mtmchkin.h"

bool testMtmchkin()
{
    Card cards[5];
    CardStats stats(16, 7472, 17, 1, 1, 1);
    cards[0] = Card(CardType::Treasure, stats);
    CardStats stats2(19, 8, 7, 16, 4, 1);
    cards[1] = Card(CardType::Battle, stats2);
    CardStats stat3(14, 19, 8, 12, 3, 12);
    cards[2] = Card(CardType::Treasure, stat3);
    CardStats stats4(14, 11, 5, 14, 6, 6);
    cards[3] = Card(CardType::Battle, stats4);
    CardStats stats5(13, 9, 20, 19, 11, 14);
    cards[4] = Card(CardType::Battle, stats5);
    Mtmchkin game("man", cards, 5);
    while(!game.isOver()){
        game.playNextCard();
    }
    if (game.getGameStatus()!=GameStatus::Win){
        return false;
    }
    return true;
}

bool testCard()
{
    Player player("Efrat",150,2);  //Efrat has 150 max HP and 2 points of force.
    CardStats stats(3, 40, 10, 30, 1, 20);
    Card card1(CardType::Treasure, stats);
    Card card2(CardType::Buff, stats);
    Card card3(CardType::Battle, stats);
    card3.printInfo();
    Card card4(CardType::Heal, stats);
    card1.applyEncounter(player);
    card2.applyEncounter(player);
    card3.applyEncounter(player);
    card4.applyEncounter(player);
    player.printInfo();
    return true;
}

bool testPlayer()
{
    Player player1("Efrat",150,2);  //Efrat has 150 max HP and 2 points of force.
    Player player2("Gandalf",300);  //Gandalf has 300 max HP and 5 points of force.
    Player player3("Daniel"); //Gandalf has 100 max HP and 5 points of force.
    player2.printInfo();
    Player player4 = player3;
    player2.addCoins(10);
    if (player1.pay(10)){
        return false;
    }
    player3.heal(10);
    player4.damage(10);
    player2.levelUp();
    player2.buff(1);
    player2.printInfo();
    if (player2.getAttackStrength() != 2 + 6 ){
        return false;
    }
    if (player2.isKnockedOut()){
        std::cout << "Player is dead";
    }
    if (player2.getLevel() != 2){
        return false;
    }
    player1.printInfo();
    player2.printInfo();
    return true;
}

void run_test(std::function<bool()> test, std::string test_name)
{
    if(!test()){
        std::cout<<test_name<<" FAILED."<<std::endl;
        std::cout << std::endl;
        return;
    }
    std::cout<<test_name<<" SUCCEEDED."<<std::endl;
    std::cout << std::endl;

}

int main(int argc, char *argv[])
{
    const int NUMBER_OF_TESTS = 3;
    std::function<bool()> tests[NUMBER_OF_TESTS] = {
        testPlayer,
        testCard,
        testMtmchkin
    };

    if (argc < 2) {
        for (int i = 0; i < NUMBER_OF_TESTS; ++i) {
            run_test(tests[i], "Test " + std::to_string(i + 1));
        }
    } else {
        int idx = -1;
        try {
            idx = std::stoi(argv[1]) - 1;
        } catch (const std::invalid_argument &e) {
            std::cerr << "Error: invalid argument: " << argv[1] << std::endl;
            return 1;
        }
        if (idx < 0 || idx > NUMBER_OF_TESTS - 1) {
            std::cerr << "Error: index out of range: " << argv[1] << std::endl;
            return 1;
        }
        run_test(tests[idx], "Test " + std::to_string(idx + 1));
    }

    return 0;
}
