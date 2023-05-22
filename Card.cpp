#include "Card.h"
#include "Player.h"

Card::Card(CardType type, const CardStats& stats)
{
    this->m_effect = type;
    switch (this->m_effect)
    {
        case CardType::Battle:
        {
            this->m_stats.force = stats.force;
            this->m_stats.loot = stats.loot;
            this->m_stats.hpLossOnDefeat = stats.hpLossOnDefeat;
        }
        case CardType::Treasure:
        {
            this->m_stats.loot = stats.loot;
        }
        case CardType::Buff:
        {
            this->m_stats.cost = stats.cost;
            this->m_stats.buff = stats.buff;
        }
        case CardType::Heal:
        {
            this->m_stats.cost = stats.cost;
            this->m_stats.heal = stats.heal;
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
            if(player.force >= this->m_stats.force)
            {
                win = true;
                player.level++;
                player.coins += this->m_stats.loot;
            }
            else
            {
                win= false;
                if(player.HP - this->m_stats.hpLossOnDefeat >0)
                {
                    player.HP -= this->m_stats.hpLossOnDefeat;

                }
                else
                {
                    player.HP = 0;
                }
            }
            printBattleResult(win);
        }


        case CardType::Treasure:
        {
            player.coins += this->m_stats.loot;
        }

        case CardType::Buff:
        {
            if(player.coins >= this->m_stats.cost)
            {
                player.coins -= this->m_stats.cost;
                player.force += this->m_stats.buff;

            }

        }

        case CardType::Heal:
        {
            if(player.coins >= this->m_stats.cost)
            {
                player.coins -= this->m_stats.cost;
                player.HP += this->m_stats.heal;

            }

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

        }
        case CardType::Treasure:
        {
            printTreasureCardInfo(this->m_stats);
        }
        case CardType::Buff:
        {
            printBuffCardInfo(this->m_stats);
        }
        case CardType::Heal:
        {
            printHealCardInfo(this->m_stats);
        }
    }
}
