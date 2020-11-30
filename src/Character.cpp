/*
File: Character.cpp
Author: Eric Schmidt
Version: 2020-11-29

Implementation file for a fantasy base class

*/
#include "Character.h"
#define DEFAULT_NAME "Generic Character"
#define DEFAULT_HIT_POINTS 1

Character::Character() {
    this->name = DEFAULT_NAME;
    this->hitPoints = DEFAULT_HIT_POINTS;
}

Character::Character(string _name, int hitDice, int level) {
    this->name = _name;
    this->hitPoints = 0;

    srand(time(NULL));
    for (int i = 0; i < level; i++) {
        this->hitPoints += rand() % hitDice;
    }
}

Character::~Character() {}

int Character::Attack() {
    return this->damage;
}

string Character::GetName() {
    return this->name;
}

void Character::TakeDamage(int damage) {
    this->hitPoints -= damage;
}

int Character::GetHP() {
    return this->hitPoints;
}