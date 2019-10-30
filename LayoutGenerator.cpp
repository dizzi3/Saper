#include "LayoutGenerator.h"

#include <QtMath>
#include "Field.h"
#include <random>
#include <algorithm>

std::list<int> LayoutGenerator::bombsPositions;

void LayoutGenerator::generateBombsPositions(){

    int rowsAndColumns = (int)qPow(NUM_OF_ROWS_AND_COL, 2);

    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, rowsAndColumns-1);

    for(int i = 0; i < BOMBS; i++){
        int rand = distr(eng);

        //while list already contains this random element
        while(bombListContains(rand))
            rand = distr(eng);

       LayoutGenerator::bombsPositions.push_back(rand);
    }
}

QGridLayout* LayoutGenerator::generate(QWidget* widget){

    LayoutGenerator::bombsPositions = std::list<int>();

    generateBombsPositions();

    QGridLayout *layout = new QGridLayout(widget);
    layout->setHorizontalSpacing(2);
    layout->setVerticalSpacing(2);

    int currentRow = 0;
    int currentColumn = 0;
    int rowsAndColumns = (int)qPow(NUM_OF_ROWS_AND_COL, 2);
    for(int i = 0; i < rowsAndColumns; i++){

        Field* field = new Field();
        field->setMaximumWidth(30);
        field->setMaximumHeight(30);

        if(bombListContains(i)){
            field->setStatus(FieldStatus::BOMB);
            field->setIcon(QIcon(":/icons/bomb_icon.png"));
        }
        else
            field->setStatus(FieldStatus::EMPTY);

        QObject::connect(field, &QPushButton::clicked, field, &Field::onClickSlot);

        layout->addWidget(field, currentRow, currentColumn);
        currentColumn++;
        if(currentColumn >= NUM_OF_ROWS_AND_COL){
            currentRow++;
            currentColumn = 0;
        }
    }

    return layout;
}

bool LayoutGenerator::bombListContains(int element){
    return (std::find(LayoutGenerator::bombsPositions.begin(), LayoutGenerator::bombsPositions.end(), element) != LayoutGenerator::bombsPositions.end());
}
