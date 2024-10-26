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
    /**
     * @brief startGame calls appropriate functions and sets values when game started/restarted
     */
    void startGame();

    /**
     * @brief redButtonPressed slot activated when red button pressed
     */
    void redButtonPressed();

    /**
     * @brief blueButtonPressed slot activated when red button pressed
     */
    void blueButtonPressed();

    /**
     * @brief iterateSequence
     * @param isReplay boolean reflecting wether function is called to replay or flash sequence
     */
    void iterateSequence(bool isReplay);

signals:

    /** @brief
     *  @param
     *  @return
     */
    void flashRedButton();

    /** @brief
     *  @param
     *  @return
     */
    void flashBlueButton();

    /** @brief
     *  @param
     *  @return
     */
    void revertRedButton();

    /** @brief
     *  @param
     *  @return
     */
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
