#include "Board.h"
#include <QtMath>

Board::Board(){
    numberOfAllFields = (int)qPow(NUM_OF_ROWS_AND_COL, 2);
}

std::list<Field*> Board::getFields(){
    return this->fields;
}

void Board::generateBoard(){
    generateBombsCoordinates();
    generateFields();
}

void Board::generateBombsCoordinates(){

    std::mt19937 eng((unsigned int)time(nullptr));

    for(int i = 0; i < BOMBS; i++){
        Coordinate* coordinate = generateRandomCoordinate(&eng);

       while(doesBombListContain(*coordinate))
            coordinate = generateRandomCoordinate(&eng);

       bombsCoordinates.push_back(*coordinate);
    }
}

Coordinate* Board::generateRandomCoordinate(std::mt19937* eng){

    std::uniform_int_distribution<> distr(0, numberOfAllFields - 1);

    int randomFieldIndex = distr(*eng);

    return Coordinate::getCoordinateBasedOnIndex(randomFieldIndex);
}

void Board::generateFields(){

    for(int i = 0; i < numberOfAllFields; i++){
        Coordinate* coordinates = Coordinate::getCoordinateBasedOnIndex(i);

        Field* field = Field::getStyledField();
        field->setCoordinates(coordinates);

        setBombStatusIfFieldIsOnList(field, *coordinates);
        fields.push_back(field);
    }
}

void Board::setBombStatusIfFieldIsOnList(Field* field, Coordinate coordinates){

    if(doesBombListContain(coordinates)){
        field->setStatus(FieldStatus::BOMB);

        //TODO: MOVE TO ON CLICK WHEN FIELD IS A BOMB
        field->setIcon(QIcon(":/icons/bomb_icon.png"));
    }

}

bool Board::doesBombListContain(Coordinate element){
    return (std::find(bombsCoordinates.begin(), bombsCoordinates.end(), element) != bombsCoordinates.end());
}
