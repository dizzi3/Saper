#include "mainwindow.h"

#include <QApplication>
#include <QGridLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    QWidget *widget = new QWidget(&window);
    QGridLayout *layout = new QGridLayout(widget);
    layout->setHorizontalSpacing(2);
    layout->setVerticalSpacing(2);

    window.setCentralWidget(widget);
    widget->setLayout(layout);

    int currentRow = 0;
    int currentColumn = 0;
    for(int i = 0; i < 64; i++){

        QPushButton* button = new QPushButton();
        button->setMaximumWidth(30);
        button->setMaximumHeight(30);

        layout->addWidget(button, currentRow, currentColumn);
        currentColumn++;
        if(currentColumn >= 8){
            currentRow++;
            currentColumn = 0;
        }
    }


    window.show();
    return a.exec();
}
