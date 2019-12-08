#ifndef GAMETIMER_H
#define GAMETIMER_H

#include <QLabel>
#include <QTimer>
#include <QObject>

class GameTimer : public QLabel{

Q_OBJECT

public:
    GameTimer();
    void stopTimer();
    int getTimeInSeconds();

private:
    QTimer timer;
    int elapsedTimeInSeconds;
    QString convertTimeInSecondsToText();

private slots:
    void increaseTimeByASecond();

};

#endif // GAMETIMER_H
