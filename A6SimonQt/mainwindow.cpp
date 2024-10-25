#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "model.h"
#include <QTimer>
#include <iostream>

 QTimer *timer;

MainWindow::MainWindow(model& model, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Create interval timer
    timer = new QTimer(this);

    // Call startGame method/slot when clicked is pressed
    ui->setupUi(this);
    connect(ui->startButton,
            &QPushButton::clicked,
            &model,
            &model::startGame);

    // Disable start on clicked
    connect(ui->startButton,
            &QPushButton::clicked,
            ui->startButton,
            &QWidget::setEnabled);

    // Set user value to 0
    connect(ui->redButton,
            &QPushButton::clicked,
            &model,
            &model::redButtonPressed);

    connect(ui->blueButton,
            &QPushButton::clicked,
            &model,
            &model::blueButtonPressed);

    ui->blueButton->setStyleSheet(
        QString("QPushButton {background-color: rgb(0,0,255);}"
                " QPushButton:pressed {background-color: rgb(150,150,255);}"));
    ui->redButton->setStyleSheet(
        QString("QPushButton {background-color: rgb(200,50,50);}"
                " QPushButton:pressed {background-color: rgb(255,150,150);}"));

    connect(&model,
            &model::flashRedButton,
            this,
            &MainWindow::setRedFlashColor);
    connect(&model,
            &model::flashBlueButton,
            this,
            &MainWindow::setBlueFlashColor);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setRedFlashColor() {
    std::cout << "setRedFlashColor called" << std::endl;
    QTimer::singleShot(1000, this,  [this]() {
        ui->redButton->setStyleSheet("background-color: rgb(255,150,150);");
    });

    QTimer::singleShot(2000, this,  [this]() {
        ui->redButton->setStyleSheet("background-color: rgb(200,50,50);");
    });
   //  ui->redButton->setStyleSheet("background-color: rgb(200,50,50);");

}

void MainWindow::setBlueFlashColor() {
    std::cout << "setBlueFlashColor called" << std::endl;
    QTimer::singleShot(1000, this,  [this]() {
        ui->blueButton->setStyleSheet("background-color: rgb(150,150,255);");
    });

    QTimer::singleShot(2000, this,  [this]() {
        ui->blueButton->setStyleSheet("background-color: rgb(0,0,255);");
    });

    //background-color: rgb(150,150,255); desat-blue
    //background-color: rgb(255,150,150);" desat-red

 //   ui->blueButton->setStyleSheet("background-color: rgb(0,0,255)");
}


// MainWindow::disableStart() {
//     ui->startButton->setEnabled(false);
// }
