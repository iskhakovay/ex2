#include "Card.h"
#include "Player.h"
#include <iostream>

Card::Card(CardType type, const CardStats& stats)
{
    this->m_effect = type;
    //this->m_stats = stats;
    switch (this->m_effect)
    {
        case CardType::Battle:
        {
            this->m_stats.force = stats.force;
            this->m_stats.loot = stats.loot;
            this->m_stats.hpLossOnDefeat = stats.hpLossOnDefeat;
            break;
        }
        case CardType::Treasure:
        {
            this->m_stats.loot = stats.loot;
            break;
        }
        case CardType::Buff:
        {
            this->m_stats.cost = stats.cost;
            this->m_stats.buff = stats.buff;
            break;
        }
        case CardType::Heal:
        {
            this->m_stats.cost = stats.cost;
            this->m_stats.heal = stats.heal;
            break;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------
void Card::applyEncounter(Player& player) const
{
    switch (this->m_effect)
    {
        case CardType::Battle:
        {
            bool win;
            if(player.getAttackStrength() >= this->m_stats.force)
            {
                win = true;
                player.levelUp();
                player.addCoins(this->m_stats.loot);
            }
            else
            {
                win= false;
                player.damage(this->m_stats.hpLossOnDefeat);
                if(player.isKnockedOut()){
                    std::cout << "Player is knocked out";
                }
            }
            printBattleResult(win);
            break;
        }


        case CardType::Treasure:
        {
            player.addCoins(this->m_stats.loot);
            break;
        }

        case CardType::Buff:
        {
            if(player.pay(this->m_stats.loot))
            {
                player.coins -= this->m_stats.cost;
                player.buff(this->m_stats.buff);

            }else{
                std::cout << "Not enough coins";
            }
            break;
        }

        case CardType::Heal:
        {
            if(player.pay(this->m_stats.loot))
            {
                player.coins -= this->m_stats.cost;
                player.heal(this->m_stats.heal);

            }
            break;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------

void Card::printInfo() const
{
    switch (this->m_effect)
    {
        case CardType::Battle:
        {
            printBattleCardInfo(this->m_stats);
            break;

        }
        case CardType::Treasure:
        {
            printTreasureCardInfo(this->m_stats);
            break;
        }
        case CardType::Buff:
        {
            printBuffCardInfo(this->m_stats);
            break;
        }
        case CardType::Heal:
        {
            printHealCardInfo(this->m_stats);
            break;
        }
    }
}
