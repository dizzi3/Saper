#include "LayoutGenerator.h"

#include <QtMath>
#include <random>
#include <algorithm>
#include <time.h>

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
        layout->addWidget(*it, (*it)->getCoordinates()->getRow(), (*it)->getCoordinates()->getColumn());
}

StyledGridLayout* LayoutGenerator::generate(QWidget* widget){

    if(instance == nullptr)
        instance = new LayoutGenerator();

    StyledGridLayout* layout = StyledGridLayout::instance(widget);

    instance->board = new Board();
    instance->board->generateBoard();

    instance->addFieldsToTheLayout(layout);

    //instance->freeInstanceMemory();

    return layout;
}

LayoutGenerator* LayoutGenerator::instance;
