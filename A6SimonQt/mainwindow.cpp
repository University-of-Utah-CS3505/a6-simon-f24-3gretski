#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "model.h"
#include <QTimer>

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

    ui->redButton->setStyleSheet(
        QString("QPushButton {background-color: rgb(0,0,255);}"
                " QPushButton:pressed {background-color: rgb(150,150,255);}"));
    ui->blueButton->setStyleSheet(
        QString("QPushButton {background-color: rgb(200,50,50);}"
                " QPushButton:pressed {background-color: rgb(255,150,150);}"));

    connect(&model,
            &model::flashRedButton,
            QTimer::singleShot(1000, this, &MainWindow::setRedFlashColor)
            );
    connect(&model,
            &model::flashBlueButton,
            QTimer::singleShot(1000, this, &MainWindow::setBlueFlashColor)
            );


    // connect(&model,
    //         &model::flashRedButton,
    //         [this]() {
    //             ui->redButton->setStyleSheet("background-color: rgb(150,150,255);}");
    //         });
    // connect(&model,
    //         &model::flashBlueButton,
    //         [this]() {
    //             ui->blueButton->setStyleSheet("background-color: rgb(255,150,150);");
    //         });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRedFlashColor() {
    ui->redButton->setStyleSheet("background-color: rgb(150,150,255);");
}

void MainWindow::setBlueFlashColor() {
    ui->blueButton->setStyleSheet("background-color: rgb(255,150,150);");
}


// MainWindow::disableStart() {
//     ui->startButton->setEnabled(false);
// }
