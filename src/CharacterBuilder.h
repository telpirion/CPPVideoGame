/*
File: CharacterBuilder.h
Author: Eric Schmidt
Version: 2020-11-29

Header file for a builder class for the Character class
*/
#ifndef CHARACTER_BUILDER_H
#define CHARACTER_BUILDER_H

#include <cstdlib>
#include <string>
#include "Character.h"
#include "time.h"

using namespace std;

int ComputeHitPoints(int level, int hitDice);

// Create a Builder class to use the Builder pattern.
class CharacterBuilder
{
public:
    CharacterBuilder();
    CharacterBuilder& SetName(string _name);
    CharacterBuilder& SetHitDice(int _hitDice);
    CharacterBuilder& SetLevel(int _level);
    Character Build();
private:
    Character character;
};

#endif