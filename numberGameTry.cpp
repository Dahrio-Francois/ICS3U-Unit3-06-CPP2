// Copyright (c) 2022 Dahrio Francois All rights reserved
//
// Created by: Dahrio Francois
// Created on: Feb 2022
// This program makes a number guessing game
//      with user input and try statements

#include <iostream>
#include <string>
#include <random>

int main() {
    // this creates the game
    std::string integerAsString;
    int integerAsNumber;
    int someRandomNumber;


    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,9]
    someRandomNumber = idist(rgen);

    // input
    std::cout << "Enter your guess (between 0 & 9): ";
    std::cin >> integerAsString;

    // process & output
    try {
        integerAsNumber = std::stoi(integerAsString);
        if (integerAsNumber != someRandomNumber) {
            std::cout << "\nIncorrect! The correct number was " <<
            someRandomNumber << "\nTry again?" << std::endl;
        } else if (integerAsNumber == someRandomNumber) {
            std::cout << "\nCorrect! You guessed the right number!";
        }
    } catch (std::invalid_argument) {
        std::cout << "\nThat was not a valid integer";
    }
}
