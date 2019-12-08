#include "Highscore.h"
#include <QSettings>

Highscore::Highscore(){

    QSettings settings("dizzie", "Saper");

    for(int i = 0; i < MAX_ELEMENTS; i++){

        QString currentKey = "highscore" + QString::number(i);
        QString usernameKey = currentKey + "_username";
        QString scoreKey = currentKey + "_score";

        int score = settings.value(scoreKey).toInt();
        if(score > 0){

            QString username = settings.value(usernameKey).value<QString>();
            highscores.push_back(HighscoreRecord(score, username));

        }

    }

}

void Highscore::addHighscore(int score, QString username){

    highscores.push_back(HighscoreRecord(score, username));

    highscores.sort(HighscoreRecord::compareHighscore);

    if(highscores.size() <= MAX_ELEMENTS){
        saveHighscores();
        return;
    }

    highscores.pop_back();
    saveHighscores();
}

std::list<HighscoreRecord> Highscore::getHighscores(){
    return this->highscores;
}

bool Highscore::isAHighscore(int score){

    if(highscores.size() < MAX_ELEMENTS)
        return true;

    for(std::list<HighscoreRecord>::iterator it = highscores.begin(); it != highscores.end(); ++it){

        if((*it).getScore() < score)
            return true;

    }

    return false;
}

void Highscore::saveHighscores(){

    QSettings settings("dizzie", "Saper");

    int index = 0;
    for(std::list<HighscoreRecord>::iterator it = highscores.begin(); it != highscores.end(); ++it, index++){

        QString currentKey = "highscore" + QString::number(index);
        QString usernameKey = currentKey + "_username";
        QString scoreKey = currentKey + "_score";

        settings.setValue(usernameKey, (*it).getUsername());
        settings.setValue(scoreKey, (*it).getScore());

    }

}

void Highscore::resetHighscore(){

    QSettings settings("dizzie", "Saper");

    settings.setValue("highscore0_score", 0);
    settings.setValue("highscore1_score", 0);
    settings.setValue("highscore2_score", 0);

    settings.setValue("highscore0_username", "");
    settings.setValue("highscore1_username", "");
    settings.setValue("highscore2_username", "");
}
