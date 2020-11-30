/*
File: main.cpp (app)
Author: Eric Schmidt
Version: 2020-11-29

Entry point for the game.
*/
#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Running app executable ... " << endl;
    cout << "Creating base character class ..." << endl;

    Character dude("Dude", 6, 1);

    cout << "Executable done." << endl;

    return 0;
}