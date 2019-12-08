#ifndef HIGHSCORERECORD_H
#define HIGHSCORERECORD_H

#include <QString>

class HighscoreRecord{

private:
    int score;
    QString username;

public:
    HighscoreRecord(int score, QString name){
        this->score = score;
        this->username = name;
    }

    int getScore(){ return this->score; }
    QString getUsername(){ return this->username; }

    static bool compareHighscore(const HighscoreRecord& h1, const HighscoreRecord& h2){
        return h1.score > h2.score;
    }

};

#endif // HIGHSCORERECORD_H
