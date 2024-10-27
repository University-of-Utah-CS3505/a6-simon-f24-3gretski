#include "mainwindow.h"
#include <QApplication>
#include "model.h"

/**
Names: Pooja Kotha and Grace Stewart
Github usernames: pkotha50 and 3gretski

Our creative element is a replay button that allows the user to rewatch a sequence once during
their turn. After they have rewatched the sequence, they can no longer replay it again. The remaining hints label
reflects if the user still has the ability to rewatch the sequence, or if they have used up that hint.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    model model;
    MainWindow w(model);
    w.show();
    return a.exec();
}
