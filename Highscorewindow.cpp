#include "Highscorewindow.h"
#include "ui_highscorewindow.h"

HighscoreWindow::HighscoreWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighscoreWindow)
{
    ui->setupUi(this);
    setWindowTitle("Najlepsze wyniki");

    highscore = new Highscore();
    setupLabels();
}

void HighscoreWindow::setupLabels(){

    std::list<HighscoreRecord> records = highscore->getHighscores();
    int index = 0;
    QString highscoreTxts[3];

    for(std::list<HighscoreRecord>::iterator it = records.begin(); it != records.end(); ++it, index++){

        highscoreTxts[index] = QString::number(index + 1) + ". "
                + (*it).getUsername() + " - " + QString::number((*it).getScore());

    }

    ui->highscore1->setText(highscoreTxts[0]);
    ui->highscore2->setText(highscoreTxts[1]);
    ui->highscore3->setText(highscoreTxts[2]);
}

HighscoreWindow::~HighscoreWindow()
{
    delete ui;
}
