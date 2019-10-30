#include "mainwindow.h"

#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include "LayoutGenerator.h"

#define NUM_OF_ROWS_AND_COL 8

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    QWidget *widget = new QWidget(&window);
    QGridLayout* layout = LayoutGenerator::generate(widget, NUM_OF_ROWS_AND_COL);

    window.setCentralWidget(widget);
    widget->setLayout(layout);

    window.show();
    return a.exec();
}
