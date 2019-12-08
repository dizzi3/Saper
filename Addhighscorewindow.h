#ifndef ADDHIGHSCOREWINDOW_H
#define ADDHIGHSCOREWINDOW_H

#include <QDialog>

namespace Ui {
class AddHighscoreWindow;
}

class AddHighscoreWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddHighscoreWindow(int score, QWidget *parent = nullptr);
    ~AddHighscoreWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddHighscoreWindow *ui;
    int score;
};

#endif // ADDHIGHSCOREWINDOW_H
