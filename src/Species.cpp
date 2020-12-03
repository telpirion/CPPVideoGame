/*
File: Character.cpp
Author: Eric Schmidt
Version: 2020-12-01

Implementation file for a fantasy species class

*/
#define DEFAULT_NAME "Generic Species"
#define DEFAULT_DESCRIPTION "Fantasy Species"

#include "Species.h"

Species::Species()
{
    this->name = DEFAULT_NAME;
    this->description = DEFAULT_DESCRIPTION;
    this->attributeAdjustments = map<string, int>{};
}

Species::Species(string _name, string _description) : Species()
{
    this->name = _name;
    this->description = _description;
}

string Species::GetName()
{
    return this->name;
}

string Species::GetDescription()
{
    return this->description;
}

void Species::AddAttributeAdjustment(Attribute attr, int adjustment)
{
    string key = attr.GetShortName();
    this->attributeAdjustments.insert(pair<string,int>(key, adjustment));
}

int Species::GetAttributeAdjustment(Attribute attr)
{
    string key = attr.GetShortName();
    auto keyValuePair = this->attributeAdjustments.find(key);
    return keyValuePair->second;
}
