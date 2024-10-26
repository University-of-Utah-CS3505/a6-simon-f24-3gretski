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
    void revertRedButton();
    void revertBlueButton();

    void gameOver(bool isGameOver);
    void stopGame(bool isGameRunning);

    void updatePercentage(int percentage);

    void enableButtons(bool isEnabled);
    void disableButtons(bool isDisabled);

private:
    std::vector<int> sequence;
    int currUserIndex;
    double progressPercentage;
    int intervalIndex;

    void flashSequence();
    void addOneToSequence();
    void verifyUserTurn(int colorVal);

    void speedUpSequence();
};

#endif // MODEL_H
