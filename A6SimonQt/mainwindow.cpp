#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "model.h"

MainWindow::MainWindow(model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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

    connect(ui->redButton,
            &QPushButton::clicked,
            &model,
            &model::redButtonPressed);
    ui->redButton->setStyleSheet(
        QString("QPushButton {background-color: rgb(0,0,255);}"
                " QPushButton:pressed {background-color: rgb(150,150,255);}"));
    ui->blueButton->setStyleSheet(
        QString("QPushButton {background-color: rgb(200,50,50);}"
                " QPushButton:pressed {background-color: rgb(255,150,150);}"));
    connect(ui->blueButton,
            &QPushButton::clicked,
            &model,
            &model::blueButtonPressed);

    //hello
}

MainWindow::~MainWindow()
{
    delete ui;
}



// MainWindow::disableStart() {
//     ui->startButton->setEnabled(false);
// }
