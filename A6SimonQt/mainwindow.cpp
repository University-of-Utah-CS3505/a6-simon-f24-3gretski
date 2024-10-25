#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "model.h"
#include <QTimer>
#include <iostream>

// Index value to keep track of Qtimer intervals
int intervalIndex;

MainWindow::MainWindow(model& model, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    intervalIndex = 1000;

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

    connect(&model,
            &model::failGame,
            this,
            &MainWindow::setBlueFlashColor);

    connect(&model,
            &model::updatePercentage,
            [this](int percentage) {
                ui->progressBar->setValue(percentage);
            });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRedFlashColor() {

    QTimer::singleShot(intervalIndex, this,  [this]() {
        ui->redButton->setStyleSheet("background-color: rgb(255,150,150);");
    });
    intervalIndex += 500;

    QTimer::singleShot(intervalIndex, this,  [this]() {
        ui->redButton->setStyleSheet("background-color: rgb(200,50,50);");
    });
    intervalIndex += 1000;
}

void MainWindow::setBlueFlashColor() {
    QTimer::singleShot(1000, this,  [this]() {
        ui->blueButton->setStyleSheet("background-color: rgb(150,150,255);");
    });
     intervalIndex += 500;

    QTimer::singleShot(2000, this,  [this]() {
        ui->blueButton->setStyleSheet("background-color: rgb(0,0,255);");
    });
    intervalIndex += 1000;
}
