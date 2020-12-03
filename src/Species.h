/*
File: Species.h
Author: Eric Schmidt
Version: 2020-12-01

Header file for a fantasy species class

*/
#ifndef SPECIES_H
#define SPECIES_H

#include <map>
#include <string>
#include "Attributes.h"

using namespace std;

class Species
{
    friend class SpeciesBuilder;
public:
    Species();
    Species(string _name, string _description);
    string GetName();
    string GetDescription();
    void AddAttributeAdjustment(Attribute attr, int adjustment);
    int GetAttributeAdjustment(Attribute attr);
private:
    string name;
    string description;
    map<string, int> attributeAdjustments;
};

#endif
