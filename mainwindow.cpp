#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Board.h"
#include <QStyle>
#include <QDesktopWidget>
#include "Highscorewindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Saper");

    int windowSize = 32 * Board::NUM_OF_ROWS_AND_COL;
    setFixedSize(windowSize, windowSize);
    centerWindow();

    installEventFilter(this);
    setStyleSheet("background-color: #898989;");
}

void MainWindow::centerWindow(){
    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            size(),
            qApp->desktop()->availableGeometry()
        )
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject* obj, QEvent* event){

    if (event->type()==QEvent::KeyPress) {
            QKeyEvent* key = static_cast<QKeyEvent*>(event);
            if ( key->key()==Qt::Key_H ) {

                HighscoreWindow* window = new HighscoreWindow();
                window->show();

            } else {
                return QObject::eventFilter(obj, event);
            }
            return true;
        } else {
            return QObject::eventFilter(obj, event);
        }

}
