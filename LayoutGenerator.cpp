#include "LayoutGenerator.h"

#include <QtMath>
#include <random>
#include <algorithm>
#include <time.h>
#include <QDebug>

LayoutGenerator* LayoutGenerator::instance;

LayoutGenerator::LayoutGenerator(){
    numberOfAllFields = (int)qPow(NUM_OF_ROWS_AND_COL, 2);
}

void LayoutGenerator::freeInstanceMemory(){
    if(instance != nullptr){
        delete instance;
        instance = nullptr;
    }
}

Coordinate generateRandomCoordinate();

void LayoutGenerator::generateBombsCoordinates(){

    for(int i = 0; i < BOMBS; i++){
        Coordinate coordinate = generateRandomCoordinate();

        while(doesBombListContain(coordinate))
            coordinate = generateRandomCoordinate();

       instance->bombsCoordinates.push_back(coordinate);
    }
}

Coordinate LayoutGenerator::generateRandomCoordinate(){

    std::mt19937 eng((unsigned int)time(nullptr));
    std::uniform_int_distribution<> distr(0, numberOfAllFields - 1);

    int randomFieldIndex = distr(eng);

    return Coordinate::getCoordinateBasedOnIndex(randomFieldIndex);
}

StyledGridLayout* LayoutGenerator::generate(QWidget* widget){

    LayoutGenerator();

    if(instance == nullptr)
        instance = new LayoutGenerator();

    instance->generateBombsCoordinates();

    StyledGridLayout* layout = StyledGridLayout::instance(widget);

    for(int i = 0; i < instance->numberOfAllFields; i++){
        Coordinate coordinates = Coordinate::getCoordinateBasedOnIndex(i);

        Field* field = Field::getStyledField();

        instance->setBombStatusIfFieldIsOnTheList(field, coordinates);

        layout->addWidget(field, coordinates.getRow(), coordinates.getColumn());
    }

    instance->freeInstanceMemory();

    return layout;
}

void LayoutGenerator::setBombStatusIfFieldIsOnTheList(Field* field, Coordinate coordinates){

    if(instance->doesBombListContain(coordinates)){
        field->setStatus(FieldStatus::BOMB);

        //TODO: MOVE TO ON CLICK WHEN FIELD IS A BOMB
        field->setIcon(QIcon(":/icons/bomb_icon.png"));
    }
    else
        field->setStatus(FieldStatus::EMPTY);

}

bool LayoutGenerator::doesBombListContain(Coordinate element){
    return (std::find(LayoutGenerator::bombsCoordinates.begin(), LayoutGenerator::bombsCoordinates.end(), element) != LayoutGenerator::bombsCoordinates.end());
}
