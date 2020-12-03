/*
File: Character.cpp
Author: Eric Schmidt
Version: 2020-11-29

Implementation file for a fantasy base class

*/
#include "Character.h"
#define DEFAULT_NAME "Generic Character"
#define DEFAULT_HIT_POINTS 1
#define DEFAULT_ATTRIBUTE 10

Character::Character()
{
    this->name = DEFAULT_NAME;
    this->hitPoints = DEFAULT_HIT_POINTS;
    this->status = ALIVE;
    this->hitDice = 1;
    this->level = 1;
}

Character::Character(string _name, int hitDice, int level) : Character()
{
    this->name = _name;
    this->hitDice = hitDice;
    this->level = level;

    srand(time(NULL));
    for (int i = 0; i < level; i++)
    {
        this->hitPoints += rand() % hitDice;
        this->maxHitPoints = this->hitPoints;
    }
}

Character::~Character() {}

int Character::Attack()
{
    return this->damage;
}

string Character::GetName()
{
    return this->name;
}

void Character::TakeDamage(int damage)
{
    this->hitPoints -= damage;

    if (this->hitPoints < 0)
    {
        this->hitPoints = 0;
        this->status = UNCONSCIOUS;
    }
}

int Character::GetHP()
{
    return this->hitPoints;
}

int Character::GetMaxHP()
{
    return this->maxHitPoints;
}

// Translate CharacterStatus from enum to string
string Character::GetCharacterStatus()
{
    string statusString = "";

    switch (this->status)
    {
        case DEAD:
            statusString = "Dead";
            break;
        case UNCONSCIOUS:
            statusString = "Unconscious";
            break;
        case ALIVE:
        default:
            statusString = "Alive";
            break;
    }
    return statusString;
}

