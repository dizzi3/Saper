#ifndef HIGHSCOREWINDOW_H
#define HIGHSCOREWINDOW_H

#include <QDialog>
#include "Highscore.h"

namespace Ui {
class HighscoreWindow;
}

class HighscoreWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HighscoreWindow(QWidget *parent = nullptr);
    ~HighscoreWindow();

private:
    Ui::HighscoreWindow *ui;
    Highscore* highscore;

    void setupLabels();
};

#endif // HIGHSCOREWINDOW_H
