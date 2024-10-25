#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(model& model, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void setRedFlashColor();
    void setBlueFlashColor();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
