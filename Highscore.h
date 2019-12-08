#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <list>
#include "HighscoreRecord.h"

class Highscore{

private:
    static const int MAX_ELEMENTS = 3;
    std::list<HighscoreRecord> highscores;

public:
    Highscore();
    void addHighscore(int score, QString username);
    std::list<HighscoreRecord> getHighscores();
    bool isAHighscore(int score);

private:
    void saveHighscores();
    void resetHighscore();

};

#endif // HIGHSCORE_H
