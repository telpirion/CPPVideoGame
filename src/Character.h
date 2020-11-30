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

using namespace std;

class Character {
    public:
        Character();
        Character(string _name, int hitDice, int level);
        ~Character();
        virtual int Attack();
        string GetName();
        void TakeDamage(int damage);
        int GetHP();
    protected:
        string name;
        int damage;
    private:
        int hitPoints;
};

#endif