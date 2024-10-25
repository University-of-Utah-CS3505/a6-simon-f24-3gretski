#include "model.h"
#include <iostream>
#include <vector>
#include <time.h>

std::vector<int> sequence = {};

model::model(QObject *parent) : QObject(parent)
{

}

void model::startGame() {
    std::cout << "clicked start" << std::endl;
    //set enabled to true
    addOneToSequence();
    addOneToSequence();
    addOneToSequence();
    flashSequence();
}

//1 bool val
void model::redButtonPressed() {
    // CurrentUserValue = 0
    // Check 0 against computer sequence/turn index at the correct index using helper
}

//0 bool val
void model::blueButtonPressed() {
    // CurrentUserValue = 1
    // Check 1 against computer sequence/turn index at the correct index using helper
}


//* Helper to Take in parameter representing which button color pressed
// computer turn index =

//Helper to display computer flash sequence
void model::flashSequence() {
    for(int sequenceColor: sequence) {
        if(sequenceColor == 1) {
            std::cout << "Flash Blue"  << std::endl;
            emit flashBlueButton();
        }
        else {
            std::cout << "Flash Red"  << std::endl;
            emit flashRedButton();
        }
    }

}

void model::addOneToSequence() {
    // add one to computer turn index
    srand(time(0));
    int random = rand() % 2;
    sequence.push_back(random);
    std::cout << "number: " << random << std::endl;

}

void model::computerTurnFlash(int sequenceColor) {

}
