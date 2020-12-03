/*
File: Attribute.h
Author: Eric Schmidt
Version: 2020-12-01

Header file for the attributes of a fantasy character

*/
#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

using namespace std;

class Attribute
{
public:
    Attribute(string _displayName, string _shortName, string _description);
    string GetDisplayName();
    string GetShortName();
    string GetDescription();
private:
    string displayName;
    string shortName;
    string description;
};

struct Attributes
{
    static const Attribute STR;
    static const Attribute DEX;
    static const Attribute CON;
    static const Attribute INT;
    static const Attribute WIS;
    static const Attribute CHA;
};

#endif