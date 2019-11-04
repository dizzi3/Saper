#include "mainwindow.h"

#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include "LayoutGenerator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    QWidget *widget = new QWidget(&window);
    StyledGridLayout* layout = LayoutGenerator::generate(widget);

    window.setCentralWidget(widget);
    widget->setLayout(layout);

    window.show();
    return a.exec();
}
