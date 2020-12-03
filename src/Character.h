/*
File: Character.h
Author: Eric Schmidt
Version: 2020-11-29

Header file for a fantasy base character class

*/
#ifndef CHARACTER_H
#define CHARACTER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include "time.h"

#include "Species.h"

using namespace std;

enum CharacterStatus
{
    ALIVE,
    UNCONSCIOUS,
    DEAD
};

class Character
{
    friend class CharacterBuilder;
public:
    Character();
    Character(string _name, int hitDice, int level);
    ~Character();
    virtual int Attack();
    string GetName();
    void TakeDamage(int damage);
    int GetHP();
    int GetMaxHP();
    string GetCharacterStatus();
    string GetSpeciesName();
protected:
    string name;
    int damage;
    CharacterStatus status;
    // Attributes
    int str_;
    int dex_;
    int con_;
    int int_;
    int wis_;
    int cha_;
private:
    Species species;
    int hitDice;
    int level;
    int hitPoints;
    int maxHitPoints;
};

#endif