
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


class Player {
private:

    const char* m_name;
    int m_level ;
    int m_force ;
    int m_maxHP ;
    int m_HP ;
    int m_coins  ;


public:
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;
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
    Player( const char* name,int maxHP , int force );
    Player(const char *name, int maxHP);
    explicit Player(const char *name);//constructor
    ~Player() = default; //deconstruct

    /**
     * Gives info about player stats
     *
     * @return
     *      void
     */
    void printInfo();

    /**
     * Levels up a player by 1 level
     *
     * @return
     *      void
     */
    void levelUp();
    int getLevel() const;/** Gives info about current player's level*/

    /**
     * Buffs player
     *
     *@param buff_force - amount of force to add
     *
     * @return
     *      void
     */
    void buff(int buff_force);

    /**
     * Heals player
     *@param heal_hp - amount of XP to add
     *
     * @return
     *      void
     */
    void heal(int heal_hp);

    /**
     * Damages player
     *@param damage_p - amount of XP to take from player
     *
     * @return
     *      void
     */
    void damage(int damage_p);

    /**
     * Adding coins to player
     *@param coins_am - amount of coins to add
     *
     * @return
     *      void
     */
    void addCoins(int coins_am);

    /**
     * Gives info about player's current attack strength
     *
     * @return
     *      int attackStrength - amount of attack strength
     */
    int getAttackStrength();

    /**
     * Checks is player's HP reached 0
     *
     * @return
     *      true - player's HP is zero
     *      false - otherwise
     */
    bool isKnockedOut() const;

    /**
     * Checks if player has enough money for his purchase
     *
     * @return
     *      true - player can afford the purchase
     *      false - otherwise
     */
    bool pay(int price);

};


#endif //EX2_PLAYER_H
