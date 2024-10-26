#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "model.h"
#include <iostream>

// Index value to keep track of Qtimer intervals

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

    // Set user value to 1
    connect(ui->redButton,
            &QPushButton::clicked,
            &model,
            &model::redButtonPressed);

    // Set user value to 0
    connect(ui->blueButton,
            &QPushButton::clicked,
            &model,
            &model::blueButtonPressed);

    // Set button color on clicked
    ui->blueButton->setStyleSheet(
        QString("QPushButton {background-color: rgb(0,0,255);}"
                " QPushButton:pressed {background-color: rgb(150,150,255);}"));
    ui->redButton->setStyleSheet(
        QString("QPushButton {background-color: rgb(200,50,50);}"
                " QPushButton:pressed {background-color: rgb(255,150,150);}"));


    // Flashing red buttons in sequence
    connect(&model,
            &model::flashRedButton,
            [this]() {
                ui->redButton->setStyleSheet("background-color: rgb(255,150,150);");
            });

    connect(&model,
            &model::revertRedButton,
            [this]() {
                ui->redButton->setStyleSheet("background-color: rgb(200,50,50);");
            });

    // Flashing blue buttons in sequence
    connect(&model,
            &model::flashBlueButton,
            [this]() {
                ui->blueButton->setStyleSheet("background-color: rgb(150,150,255);");
            });

    connect(&model,
            &model::revertBlueButton,
            [this]() {
                ui->blueButton->setStyleSheet("background-color: rgb(0,0,255);");
            });

    // Update progress bar
    connect(&model,
            &model::updatePercentage,
            [this](int percentage) {
                ui->progressBar->setValue(percentage);
            });

    // Disable buttons during computer turn
    connect(&model,
            &model::disableButtons,
            ui->redButton,
            &QWidget::setEnabled);

    connect(&model,
            &model::disableButtons,
            ui->blueButton,
            &QWidget::setEnabled);

    // Enable buttons during user turns
    connect(&model,
            &model::enableButtons,
            ui->redButton,
            &QWidget::setEnabled);

    connect(&model,
            &model::enableButtons,
            ui->blueButton,
            &QWidget::setEnabled);

    // Fail Game
    connect(&model,
            &model::failGame,
            this,
            &QWidget::close);

}

MainWindow::~MainWindow()
{
    delete ui;
}
