#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "model.h"
#include <iostream>

// Index value to keep track of Qtimer intervals

MainWindow::MainWindow(model& model, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    intervalIndex = 1000;

    ui->setupUi(this);

    ui->gameOverButton->hide();

    // Call startGame method/slot when clicked is pressed
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

    // Start over when user clicks on Game Over Buttons
    connect(ui->gameOverButton,
            &QPushButton::clicked,
            &model,
            &model::startGame);

    connect(ui->gameOverButton,
            &QPushButton::clicked,
            &model,
            &model::startGame);

    // Disable & Hide Game Over Button
    connect(ui->gameOverButton,
            &QPushButton::clicked,
            ui->gameOverButton,
            &QWidget::setDisabled);

    connect(ui->gameOverButton,
            &QPushButton::clicked,
            ui->gameOverButton->hide);


    // Set button color, and set color on clicked
    ui->blueButton->setStyleSheet(
        QString("QPushButton {background-color: rgb(0,0,255);"
                "border: 2px solid rgb(0,0,255); border-radius: 5px;}"
                "QPushButton:pressed {background-color: rgb(150,150,255);"
                "border: 2px solid rgb(150,150,255); border-radius: 5px;}"));
    ui->redButton->setStyleSheet(
        QString("QPushButton {background-color: rgb(200,50,50);"
                "border: 2px solid rgb(200,50,50); border-radius: 5px;}"
                "QPushButton:pressed {background-color: rgb(255,150,150);"
                "border: 2px solid rgb(255,150,150); border-radius: 5px;}"));


    // Flashing red buttons in sequence
    connect(&model,
            &model::flashRedButton,
            [this]() {
                ui->redButton->setStyleSheet(QString("QPushButton {background-color: rgb(255,150,150);"
                "border: 2px solid rgb(255,150,150); border-radius: 5px;}"
                "QPushButton:pressed {background-color: rgb(255,150,150);"
                "border: 2px solid rgb(255,150,150); border-radius: 5px;}"));
            });

    connect(&model,
            &model::revertRedButton,
            [this]() {
                ui->redButton->setStyleSheet(QString("QPushButton {background-color: rgb(200,50,50);"
                 "border: 2px solid rgb(200,50,50); border-radius: 5px;}"
                 "QPushButton:pressed {background-color: rgb(255,150,150);"
                 "border: 2px solid rgb(255,150,150); border-radius: 5px;}"));
            });

    // Flashing blue buttons in sequence
    connect(&model,
            &model::flashBlueButton,
            [this]() {
                ui->blueButton->setStyleSheet(QString("QPushButton {background-color: rgb(150,150,255);"
                  "border: 2px solid rgb(150,150,255); border-radius: 5px;}"
                  "QPushButton:pressed {background-color: rgb(150,150,255);"
                  "border: 2px solid rgb(150,150,255); border-radius: 5px;}"));
            });

    connect(&model,
            &model::revertBlueButton,
            [this]() {
                ui->blueButton->setStyleSheet(QString("QPushButton {background-color: rgb(0,0,255);"
                  "border: 2px solid rgb(0,0,255); border-radius: 5px;}"
                  "QPushButton:pressed {background-color: rgb(150,150,255);"
                  "border: 2px solid rgb(150,150,255); border-radius: 5px;}"));
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

    // Make game over button visible
    connect(&model,
            &model::gameOver,
            ui->gameOverButton,
            &QWidget::setVisible);

    // Enabling the game over button
    connect(&model,
            &model::gameOver,
            ui->gameOverButton,
            &QWidget::setEnabled);


    // Disable red and blue buttons on game over
    connect(&model,
            &model::stopGame,
            ui->redButton,
            &QWidget::setEnabled);

    connect(&model,
            &model::stopGame,
            ui->blueButton,
            &QWidget::setEnabled);

    //Disable replay button when user clicks
    connect(ui->replayButton,
            &QPushButton::clicked,
            ui->replayButton,
            &QWidget::setEnabled);

    //enable button when sequence has been flashed
    connect(&model,
            &model::enableReplay,
            ui->replayButton,
            &QWidget::setEnabled);

    //disable button before sequence finishes
    connect(&model,
            &model::disableReplay,
            ui->replayButton,
            &QWidget::setDisabled);

}

MainWindow::~MainWindow()
{
    delete ui;
}
