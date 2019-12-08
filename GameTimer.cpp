#include "GameTimer.h"

GameTimer::GameTimer(){

    elapsedTimeInSeconds = 0;
    setText(convertTimeInSecondsToText());
    setStyleSheet("font-weight: bold; font-size: 26px; color: white;");

    connect(&timer, SIGNAL(timeout()), this, SLOT(increaseTimeByASecond()));
    timer.start(1000);

}

void GameTimer::stopTimer(){
    timer.stop();
}

int GameTimer::getTimeInSeconds(){
    return elapsedTimeInSeconds;
}

QString GameTimer::convertTimeInSecondsToText(){

    int minutes = elapsedTimeInSeconds / 60;
    QString minutesStr;
    if(minutes < 10)
        minutesStr.append('0');

    minutesStr.append(QString::number(minutes));

    int seconds = elapsedTimeInSeconds % 60;
    QString secondsStr;
    if(seconds < 10)
        secondsStr.append('0');

    secondsStr.append(QString::number(seconds));

    QString displayText = minutesStr + ":" + secondsStr;

    return displayText;
}

void GameTimer::increaseTimeByASecond(){

    elapsedTimeInSeconds++;
    setText(convertTimeInSecondsToText());

}
