#include "model.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <QTimer>

model::model(QObject *parent) : QObject(parent)
{
    sequence = {};
    intervalIndex = 1000;
}

void model::startGame() {
    std::cout << "clicked start" << std::endl;
    //set enabled to true
    addOneToSequence();
 //   addOneToSequence();
 //   addOneToSequence();
    flashSequence();
}

//1 bool val
void model::redButtonPressed() {
    verifyUserTurn(1);

    // Check 1 against computer sequence/turn index at the correct index using helper

}

//0 bool val
void model::blueButtonPressed() {
    verifyUserTurn(0);
    // CurrentUserValue = 0
    // Check 0 against computer sequence/turn index at the correct index using helper
}


//* Helper to Take in parameter representing which button color pressed
// computer turn index =
void model::verifyUserTurn(int colorVal) {
    if(sequence[currUserIndex] != colorVal) {
//        std::cout << "Fail game emit reached"  << std::endl;
        emit failGame();
    }

    progressPercentage = 100 * ((double)currUserIndex + 1 / (double)sequence.size());
    emit updatePercentage((int)progressPercentage);


    //either check here or when progress bar 100% and call addOneToSequence and flashSequence
    currUserIndex++;

    //
    if(progressPercentage == 100.0) {
        //pause before starting the computer turn(for progress bar)
        QTimer::singleShot(intervalIndex, this, [this]() {addOneToSequence();}
        );

        flashSequence();
        intervalIndex += 1000;
    }
}

//Helper to display computer flash sequence
void model::flashSequence() {
    emit disableButtons(true);
    currUserIndex = 0;
    progressPercentage = 0;

    for(int sequenceColor: sequence) {
        if(sequenceColor == 0) {
            std::cout << "Flash Blue from model"  << std::endl;
            emit flashBlueButton();
        }
        else {
            std::cout << "Flash Red from model"  << std::endl;
            emit flashRedButton();
        }
    }

    emit enableButtons(true);
}

void model::addOneToSequence() {
    srand(time(0));
    int random = rand() % 2;
    sequence.push_back(random);
    std::cout << "number: " << random << std::endl;

}
