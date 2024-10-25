#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <vector>

class model : public QObject
{
    Q_OBJECT
public:
    explicit model(QObject *parent = nullptr);

public slots:
    void startGame();
    void redButtonPressed();
    void blueButtonPressed();

signals:
    void flashRedButton();
    void flashBlueButton();
    void failGame();

private:
    std::vector<int> sequence;
    int currUserIndex;
    void flashSequence();
    void addOneToSequence();
    void computerTurnFlash(int sequenceColor);
    void verifyUserTurn(int colorVal);
};

#endif // MODEL_H
