#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Board.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Saper");

    int windowSize = 32 * Board::NUM_OF_ROWS_AND_COL;
    setFixedSize(windowSize, windowSize);

    setStyleSheet("background-color: #898989;");
}

MainWindow::~MainWindow()
{
    delete ui;
}
