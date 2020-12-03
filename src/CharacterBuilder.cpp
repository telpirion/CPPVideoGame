/*
File: CharacterBuilder.cpp
Author: Eric Schmidt
Version: 2020-11-29

Implementation file for a Character object Builder class.
*/
#include "CharacterBuilder.h"

// Utility function for computing hit points
int ComputeHitPoints(int level, int hitDice)
{
    int hitPoints = 0;

    srand(time(NULL));
    for (int i = 0; i < level; i++)
    {
        hitPoints += rand() % hitDice;
    }
    return hitPoints;
}

CharacterBuilder::CharacterBuilder()
{
    Character newCharacter;
    this->character = newCharacter;
}

CharacterBuilder& CharacterBuilder::SetName(string _name)
{
    this->character.name = _name;
    return *this;
}

CharacterBuilder& CharacterBuilder::SetHitDice(int _hitDice)
{
    this->character.hitDice = _hitDice;
    int hitPoints = ComputeHitPoints(this->character.level, _hitDice);
    this->character.hitPoints = hitPoints;
    this->character.maxHitPoints = hitPoints;
    return *this;
}

CharacterBuilder& CharacterBuilder::SetLevel(int _level)
{
    this->character.level = _level;
    int hitPoints = ComputeHitPoints(_level, this->character.hitDice);
    this->character.hitPoints = hitPoints;
    this->character.maxHitPoints = hitPoints;
    return *this;
}

CharacterBuilder& CharacterBuilder::SetSpecies(Species _species)
{
    this->character.species = _species;
    return *this;
}

Character CharacterBuilder::Build()
{
    return this->character;
}