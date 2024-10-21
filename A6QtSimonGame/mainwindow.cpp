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
}

MainWindow::~MainWindow()
{
    delete ui;
}
