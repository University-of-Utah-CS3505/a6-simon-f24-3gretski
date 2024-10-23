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

}

//1 bool val
void model::redButtonPressed() {

}

//0 bool val
void model::blueButtonPressed() {

}

// Helper to Take in parameter representing which button color pressed

//Helper to display computer flash sequence
void model::flashSequence() {
    for(int sequenceColor: sequence) {
        if(sequenceColor == 1) {
            emit flashBlueButton();
        }
        else {
            emit flashRedButton();
        }
    }

}

void model::addOneToSequence() {
    srand(time(0));
    int random = rand() % 2;
    sequence.push_back(random);
    std::cout << "number: " << random << std::endl;

}

void model::computerTurnFlash(int sequenceColor) {

}
