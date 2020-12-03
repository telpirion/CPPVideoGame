/*
File: Attributes.cpp
Author: Eric Schmidt
Version: 2020-12-01

Implementation file for attributes constants

*/
#include "Attributes.h"

Attribute::Attribute(string _displayName, string _shortName, string _description)
{
    this->displayName = _displayName;
    this->shortName = _shortName;
    this->description = _description;
}

string Attribute::GetDisplayName()
{
    return this->displayName;
}

string Attribute::GetShortName()
{
    return this->shortName;
}

string Attribute::GetDescription()
{
    return this->description;
}

const Attribute Attributes::STR = Attribute {
    "Strength",
    "STR",
    "Strength description"
};
const Attribute Attributes::DEX = Attribute {
    "Dexterity",
    "DEX",
    "Dexterity description"
};
const Attribute Attributes::CON = Attribute {
    "Constitution",
    "CON",
    "Constitution description"
};
const Attribute Attributes::INT = Attribute {
    "Intelligence",
    "INT",
    "Intelligence description"
};
const Attribute Attributes::WIS = Attribute {
    "Wisdom",
    "WIS",
    "Wisdom description"
};
const Attribute Attributes::CHA = Attribute {
    "Charisma",
    "CHA",
    "Charisma description"
};
