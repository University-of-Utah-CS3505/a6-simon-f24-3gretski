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
    void iterateSequence(int interval);

signals:
    void flashRedButton();
    void flashBlueButton();
    void revertRedButton();
    void revertBlueButton();

    void gameOver(bool isGameOver);
    void stopGame(bool isGameRunning);

    void updatePercentage(int percentage);

    void enableButtons(bool isEnabled);
    void disableButtons(bool isEnabled);

    void enableReplay(bool isEnabled);
    void disableReplay(bool isEnabled);

private:
    std::vector<int> sequence;
    int currUserIndex;
    double progressPercentage;
    int intervalIndex;

    void extracted();
    void flashSequence();
    void addOneToSequence();
    void verifyUserTurn(int colorVal);

    void speedUpSequence();
};

#endif // MODEL_H
