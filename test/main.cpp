/*
File: main.cpp (test)
Author: Eric Schmidt
Version: 2020-11-29

Runs the GoogleTest test suites.

*/
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}