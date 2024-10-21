#include "model.h"
#include <iostream>

model::model(QObject *parent) : QObject(parent)
{

}

void model::startGame() {
    std::cout << "clicked start" << std::endl;
}
