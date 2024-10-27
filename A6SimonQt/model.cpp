#include "model.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <QTimer>

model::model(QObject *parent) : QObject(parent)
{
    sequence = {};
    intervalIndex = 700;
    currUserIndex = 0;
}

void model::startGame() {
    // Reset the game data
    sequence = {};
    currUserIndex = 0;
    intervalIndex = 700;
    progressPercentage = 0;

    // Add to the sequence
    addOneToSequence();
    flashSequence();
}

void model::redButtonPressed() {
    //represent red as 1
    verifyUserTurn(1);
}

void model::blueButtonPressed() {
    //represent blue as 0
    verifyUserTurn(0);
}

void model::verifyUserTurn(int colorVal) {
    if(sequence[currUserIndex] != colorVal) {
        emit gameOver(true);
        emit stopGame(false);
    }
    else {
        progressPercentage = 100 * (((double)currUserIndex + 1.0 ) / (double)sequence.size());
        emit updatePercentage((int)progressPercentage);

        currUserIndex++;

        if(progressPercentage == 100.0) {
            addOneToSequence();
            flashSequence();
        }
    }
}

// void model::speedUpSequence()
// {
//     if (sequence.size() >= 9) {
//         intervalIndex += 200;
//     }
//     else {
//         intervalIndex += 2000 - (sequence.size() * 200);
//     }
// }

void model::iterateSequence(bool isReplay)
{
    int interval = intervalIndex;
    for(int sequenceColor: sequence) {
        if(sequenceColor == 0) {
            QTimer::singleShot(interval, this, [this]() { emit flashBlueButton(); });

            if(!isReplay) {
                intervalIndex += 500;
            }
            interval += 500;

            QTimer::singleShot(interval, this, [this]() { emit revertBlueButton(); });

            if(!isReplay) {
                intervalIndex += 1000;
            }
            interval += 1000;

            // if (!isReplay) {
            //     speedUpSequence();
            // }

        }
        //when sequence color is red
        else {
            QTimer::singleShot(interval, this,[this]() { emit flashRedButton(); });

            if(!isReplay) {
                intervalIndex += 500;
            }
            interval += 500;

            QTimer::singleShot(interval, this, [this]() { emit revertRedButton(); });

            if(!isReplay) {
                intervalIndex += 1000;
            }
            interval += 1000;

            // if (!isReplay) {
            //     speedUpSequence();
            // }

        }
    }
}

void model::flashSequence() {
    emit disableButtons(false);
    emit disableReplay(true);

    currUserIndex = 0;
    progressPercentage = 0;

    QTimer::singleShot(500, this, [this]() { emit updatePercentage((int)progressPercentage); });

    iterateSequence(false);

    // Enable red and blue buttons after the delayed sequence has been played out
    QTimer::singleShot(intervalIndex - 2000, this, [this]() { emit enableButtons(true); });

    QTimer::singleShot(intervalIndex - 2000, this, [this]() {std::cout << "Buttons Enabled" << std::endl; });

    QTimer::singleShot(intervalIndex - 2000, this, [this]() { emit enableReplay(true); });

    intervalIndex = 700;
}

void model::addOneToSequence() {
    srand(time(0));
    int random = rand() % 2;
    sequence.push_back(random);
}
