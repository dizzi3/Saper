#include "Addhighscorewindow.h"
#include "ui_addhighscorewindow.h"
#include "Highscore.h"

AddHighscoreWindow::AddHighscoreWindow(int score, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddHighscoreWindow)
{
    this->score = score;
    ui->setupUi(this);
    setWindowTitle("Dodaj najlepszy wynik");
}

AddHighscoreWindow::~AddHighscoreWindow()
{
    delete ui;
}

void AddHighscoreWindow::on_pushButton_clicked()
{
    QString username = ui->plainTextEdit->toPlainText();

    Highscore* h = new Highscore();
    h->addHighscore(score, username);

    close();
}
