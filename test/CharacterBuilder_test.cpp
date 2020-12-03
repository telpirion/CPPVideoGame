/*
File: CharacterBuilder_test.cpp
Author: Eric Schmidt
Version: 2020-11-29

Unit tests for CharacterBuilder class in src/ folder.
*/
#include "gtest/gtest.h"
#include "CharacterBuilder.h"
#include "Character.h"
#include <string>

using namespace std;

TEST(CharacterBuilderTest, createsInstanceOfCharacter)
{
    string expectedName = "Built Character";

    Character character = CharacterBuilder{}
        .SetName(expectedName)
        .SetHitDice(10)
        .SetLevel(2)
        .Build();

    EXPECT_EQ(character.GetName(), expectedName);
}