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
     * @brief iterateSequence iterates through sequence, slot activated when replay button clicked
     * @param isReplay boolean reflecting wether function is called to replay or flash sequence
     */
    void iterateSequence(bool isReplay);

signals:

    /**
     * @brief flashRedButton flash red button signal
     */
    void flashRedButton();

    /**
     * @brief flashBlueButton flash blue button signal
     */
    void flashBlueButton();

    /**
     * @brief revertRedButton revert red button signal
     */
    void revertRedButton();

    /**
     * @brief revertBlueButton revert blue button signal
     */
    void revertBlueButton();

    /**
     * @brief gameOver game over signal
     * @param isGameOver boolean stating wether game is over or not
     */
    void gameOver(bool isGameOver);

    /**
     * @brief stopGame stop game signal
     * @param isGameRunning boolean stating wether game is running or not
     */
    void stopGame(bool isGameRunning);

    /**
     * @brief updatePercentage update percentage signal
     * @param percentage value represents percentage of user moves in sequence completed
     */
    void updatePercentage(int percentage);

    /**
     * @brief enableButtons enable buttons signal
     * @param isEnabled boolean representing if buttons are enabled
     */
    void enableButtons(bool isEnabled);

    /**
     * @brief disableButtons disable buttons signal
     * @param isEnabled boolean representing if buttons are enabled
     */
    void disableButtons(bool isEnabled);

    /**
     * @brief enableReplay enable replay signal
     * @param isEnabled boolean representing if buttons are enabled
     */
    void enableReplay(bool isEnabled);

    /**
     * @brief disableReplay disable replay signal
     * @param isEnabled boolean representing if buttons are enabled
     */
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
