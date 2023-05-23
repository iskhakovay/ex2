
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


class Player {
private:

    const char* name;
    int level ;
    int force ;
    int maxHP ;
    int HP ;
    int coins  ;
    /**
    *C'tor of Player:
    *
    * @param level - The current level of the player.
    * @param force - The current state of player's force.
    * @param maxHP - The current max health points of the player.
    * @param HP - The current health point's state of the player.
    * @param coins - The current amount of coins that player has.
    * @param name - The player name that is set during c'tor.
    * @param DEFAULT_MAX_HP - default max hp.
    * @param DEFAULT_FORCE - default force.
    */


public:
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;
    Player( const char* name,int maxHP , int force );
    explicit Player(const char *name);
    Player(const char *name, int maxHP);//constructor
    ~Player() = default; //deconstruct

    void printInfo(); /** Gives info about player stats*/
    void levelUp();/** Levels up a player by 1 level*/
    int getLevel() const;/** Gives info about current player's level*/
    void buff(int buff_force);/** Buffs player*/
    void heal(int heal_hp);/** Heals player*/
    void damage(int damage_p);/** Damages player*/
    void addCoins(int coins_am);/** Adding coins to player*/
    int getAttackStrength();/** Gives info about player's current attack strength*/
    bool isKnockedOut() const;/** Checks is player's HP reached 0*/
    bool pay(int price);/** Checks if player has enough money for his purchase*/

};


#endif //EX2_PLAYER_H
