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
    void enableBothButtons();

signals:
    void flashRedButton();
    void flashBlueButton();
    void revertRedButton();
    void revertBlueButton();
    void failGame();
    void updatePercentage(int percentage);
    void enableButtons(bool isEnabled);
    void disableButtons(bool isEnabled);

private:
    std::vector<int> sequence;
    int currUserIndex;
    double progressPercentage;
    int intervalIndex;

    void flashSequence();
    void addOneToSequence();
    void verifyUserTurn(int colorVal);

};

#endif // MODEL_H
