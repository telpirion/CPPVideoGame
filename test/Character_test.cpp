/*
File: Character_test.cpp
Author: Eric Schmidt
Version: 2020-11-29

Unit tests for Character class in src/ folder.
*/
#include "gtest/gtest.h"
#include <iostream>
#include <string>

#ifdef USE_BAZEL
#   include "src/Character.h"
#   include "src/CharacterBuilder.h"
#   include "src/Species.h"
#else
#   include "Character.h"
#   include "CharacterBuilder.h"
#   include "Species.h"
#endif

using namespace std;

// Create a test fixture for Character class testing.
class CharacterTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        this->c1 = new Character();
        this->c2 = new Character("Test", 6 /* HitDice */, 5 /* Level */);

        Species species = Species {
            "Test Species", "Test Species Description"
        };

        auto builder = CharacterBuilder {}
            .SetName("Test Character 3")
            .SetHitDice(10)
            .SetLevel(2)
            .SetSpecies(species);

        Character cTemp = builder.Build();
        this->c3 = &cTemp;
    }

    Character* c1;
    Character* c2;
    Character* c3;

    void TearDown() override
    {
        this->c1 = nullptr;
        this->c2 = nullptr;
        this->c3 = nullptr;
    }
};


// Test base character creation.
TEST_F(CharacterTest, createsGenericCharacter)
{
    string expectedStr = "Generic Character";
    EXPECT_EQ(c1->GetName(), expectedStr);

    int expectedHP =  1;
    EXPECT_EQ(c1->GetHP(), expectedHP);
}

// Test a simple, custom character.
TEST_F(CharacterTest, createsCustomCharacterWithCorrectHitDice)
{
    string expectedStr = "Test";
    EXPECT_EQ(c2->GetName(), expectedStr);

    int expectedMinimumHitPoints = 5;
    EXPECT_GE(c2->GetHP(), expectedMinimumHitPoints);

    string expectedStatus = "Alive";
    EXPECT_EQ(c2->GetCharacterStatus(), expectedStatus);
}

// Test applying damage to character object.
TEST_F(CharacterTest, appliesDamageToCharacter)
{
    int c2MaxHP = c2->GetHP();
    int expectedRemainingHP = c2MaxHP - 3;

    c2->TakeDamage(3);

    EXPECT_EQ(c2->GetHP(), expectedRemainingHP);
    EXPECT_LT(c2->GetHP(), c2->GetMaxHP());
}

// Test unconscious and dying conditions
TEST_F(CharacterTest, setsNegativeHPToZero)
{
    c1->TakeDamage(10);
    EXPECT_EQ(c1->GetHP(), 0);

    string expectedStatus = "Unconscious";
    EXPECT_EQ(c1->GetCharacterStatus(), expectedStatus);
}

// Test complex character built from the CharacterBuilder
TEST_F(CharacterTest, createsComplexCustomCharacter)
{
    string actualSpeciesName = c3->GetSpeciesName();
    string expectedSpeciesName = "Test Species";

    EXPECT_EQ(actualSpeciesName, expectedSpeciesName);
}