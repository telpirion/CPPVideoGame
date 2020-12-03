/*
File: Species_test.cpp
Author: Eric Schmidt
Version: 2020-12-01

Unit tests for Species class in src/ folder.
*/
#include "gtest/gtest.h"
#include "Species.h"
#include "Attributes.h"
#include <string>

using namespace std;

// Create a test fixture for Character class testing.
class SpeciesTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        this->s1 = new Species();
        this->s2 = new Species("Test", "Test species");

        this->s2->AddAttributeAdjustment(Attributes::CON, 2);
        this->s2->AddAttributeAdjustment(Attributes::INT, -1);
    }

    Species* s1;
    Species* s2;

    void TearDown() override
    {
        this->s1 = nullptr;
        this->s2 = nullptr;
    }
};

// Test base species creation.
TEST_F(SpeciesTest, createsGenericSpecies)
{
    string expectedName = "Generic Species";
    EXPECT_EQ(s1->GetName(), expectedName);

    string expectedDescription =  "Fantasy Species";
    EXPECT_EQ(s1->GetDescription(), expectedDescription);
}

// Test customized species creation
TEST_F(SpeciesTest, createsCustomSpecies)
{
    string expectedName = "Test";
    EXPECT_EQ(s2->GetName(), expectedName);

    string expectedDescription =  "Test species";
    EXPECT_EQ(s2->GetDescription(), expectedDescription);

    int expectedIntAdjustment = -1;
    int expectedConAdjustment = 2;

    int actualIntAdjustment = s2->GetAttributeAdjustment(Attributes::INT);
    int actualConAdjustment = s2->GetAttributeAdjustment(Attributes::CON);
    EXPECT_EQ(expectedConAdjustment, actualConAdjustment);
    EXPECT_EQ(expectedIntAdjustment, actualIntAdjustment);
}