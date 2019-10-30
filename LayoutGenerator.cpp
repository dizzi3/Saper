#include "LayoutGenerator.h"

#include <QtMath>
#include "Field.h"

QGridLayout* LayoutGenerator::generate(QWidget* widget, int numberOfRows){

    QGridLayout *layout = new QGridLayout(widget);
    layout->setHorizontalSpacing(2);
    layout->setVerticalSpacing(2);

    int currentRow = 0;
    int currentColumn = 0;
    int rowsAndColumns = (int)qPow(numberOfRows, 2);
    for(int i = 0; i < rowsAndColumns; i++){

        Field* field = new Field();
        field->setMaximumWidth(30);
        field->setMaximumHeight(30);

        layout->addWidget(field, currentRow, currentColumn);
        currentColumn++;
        if(currentColumn >= numberOfRows){
            currentRow++;
            currentColumn = 0;
        }
    }

    return layout;
}
