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
    void updatePercentage(int percentage);

private:
    std::vector<int> sequence;
    int currUserIndex;
    double progressPercentage;

    void flashSequence();
    void addOneToSequence();
    void verifyUserTurn(int colorVal);

};

#endif // MODEL_H
