#include "model.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <QTimer>

model::model(QObject *parent) : QObject(parent)
{
    sequence = {};
    intervalIndex = 100;
    currUserIndex = 0;
}

void model::startGame() {
    std::cout << "clicked start" << std::endl;
    //set enabled to true
    addOneToSequence();

    flashSequence();
}

//1 bool val
void model::redButtonPressed() {
    verifyUserTurn(1);
    std::cout << "red button pressed" << std::endl;
    // Check 1 against computer sequence/turn index at the correct index using helper

}

//0 bool val
void model::blueButtonPressed() {
    verifyUserTurn(0);

    std::cout << "blue button pressed" << std::endl;
    // CurrentUserValue = 0
    // Check 0 against computer sequence/turn index at the correct index using helper
}

void model::enableBothButtons() {
    //emit enableButtons(true);
}

//* Helper to Take in parameter representing which button color pressed
// computer turn index =
void model::verifyUserTurn(int colorVal) {
    if(sequence[currUserIndex] != colorVal) {
//        std::cout << "Fail game emit reached"  << std::endl;
        emit failGame();
    }

    progressPercentage = 100 * (((double)currUserIndex + 1.0 ) / (double)sequence.size());
    emit updatePercentage((int)progressPercentage);


    //either check here or when progress bar 100% and call addOneToSequence and flashSequence
    currUserIndex++;

    //
    if(progressPercentage == 100.0) {
        //pause before starting the computer turn(for progress bar)
        //QTimer::singleShot(intervalIndex, this, &model::addOneToSequence);

        addOneToSequence();

        flashSequence();
        //intervalIndex += 100;
    }
}

//Helper to display computer flash sequence
void model::flashSequence() {
    std::cout << "Sequence Start" << std::endl;

    //emit disableButtons(false);
    currUserIndex = 0;
    progressPercentage = 0;

    emit updatePercentage((int)progressPercentage);

    for(int sequenceColor: sequence) {
        if(sequenceColor == 0) {
            std::cout << "Flash Blue"  << std::endl;
            emit flashBlueButton();
        }
        else {
            //std::cout << "Flash Red from model"  << std::endl;
            std::cout << "Flash Red"  << std::endl;
            emit flashRedButton();
        }
    }

    std::cout << "Sequence End" << std::endl;

}

void model::addOneToSequence() {
    srand(time(0));
    int random = rand() % 2;
    sequence.push_back(random);
    //std::cout << "number: " << random << std::endl;

}
