#include "LayoutGenerator.h"

#include <QtMath>
#include <random>
#include <algorithm>
#include <time.h>
#include "GameTimer.h"

LayoutGenerator::LayoutGenerator() {}

void LayoutGenerator::freeInstanceMemory(){
    if(instance != nullptr){

        delete instance->board;
        instance->board = nullptr;

        delete instance;
        instance = nullptr;
    }
}

void LayoutGenerator::addFieldsToTheLayout(StyledGridLayout* layout){
    std::list<Field*> fields = instance->board->getFields();

    for(std::list<Field*>::iterator it = fields.begin(); it != fields.end(); ++it)
        layout->addWidget(*it, (*it)->getCoordinates()->getRow() + 2, (*it)->getCoordinates()->getColumn() + 2);
}

StyledGridLayout* LayoutGenerator::generate(QWidget* widget){

    if(instance == nullptr)
        instance = new LayoutGenerator();

    StyledGridLayout* layout = StyledGridLayout::instance(widget);

    GameTimer* gameTimer = new GameTimer();
    layout->addWidget(gameTimer, 0, 0, Board::NUM_OF_ROWS_AND_COL, 0, Qt::AlignTop | Qt::AlignCenter);

    instance->board = new Board(gameTimer);
    instance->board->generateBoard();

    instance->addFieldsToTheLayout(layout);

    //instance->freeInstanceMemory();

    return layout;
}

LayoutGenerator* LayoutGenerator::instance;
