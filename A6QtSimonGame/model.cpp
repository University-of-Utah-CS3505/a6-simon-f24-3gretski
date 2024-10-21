#include "model.h"
#include <iostream>
#include <vector>


std::vector<int> sequence = {};

model::model(QObject *parent) : QObject(parent)
{

}

void model::startGame() {
    std::cout << "clicked start" << std::endl;
}

void model::redButtonPressed() {

}

void model::blueButtonPressed() {

}

// Helper to Take in parameter representing which button color pressed
void model::flashSequence() {

}
