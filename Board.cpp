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

        if(doesBombListContain(*coordinates))
            setBombStatus(field);

        fields.push_back(field);
    }

    setNonBombFieldsValues();
}

bool Board::doesBombListContain(Coordinate element){
    return (std::find(bombsCoordinates.begin(), bombsCoordinates.end(), element) != bombsCoordinates.end());
}

void Board::setBombStatus(Field* field){

    field->setStatus(FieldStatus::BOMB);

    //TODO: MOVE TO ON CLICK WHEN FIELD IS A BOMB
    field->setIcon(QIcon(":/icons/bomb_icon.png"));
}

void Board::setNonBombFieldsValues(){

    for(std::list<Coordinate>::iterator it = bombsCoordinates.begin(); it != bombsCoordinates.end(); ++it)
        updateBombSurroundingFieldsValues(&(*it));

    for(std::list<Field*>::iterator it = fields.begin(); it != fields.end(); ++it)
        (*it)->updateTextBasedOnValue();

}

void Board::updateBombSurroundingFieldsValues(Coordinate* bombCoordinate){
    int bombColumn = bombCoordinate->getColumn();
    int bombRow = bombCoordinate->getRow();

    if(bombColumn - 1 >= 0){
        increaseFieldValueIfExists(bombRow, bombColumn - 1);

        if(bombRow - 1 >= 0)
            increaseFieldValueIfExists(bombRow - 1, bombColumn - 1);

        if(bombRow + 1 < NUM_OF_ROWS_AND_COL)
            increaseFieldValueIfExists(bombRow + 1, bombColumn - 1);
    }

    if(bombColumn + 1 < NUM_OF_ROWS_AND_COL){
        increaseFieldValueIfExists(bombRow, bombColumn + 1);

        if(bombRow - 1 >= 0)
            increaseFieldValueIfExists(bombRow - 1, bombColumn + 1);

        if(bombRow + 1 < NUM_OF_ROWS_AND_COL)
            increaseFieldValueIfExists(bombRow + 1, bombColumn + 1);
    }

    if(bombRow - 1 >= 0)
        increaseFieldValueIfExists(bombRow - 1, bombColumn);

    if(bombRow + 1 < NUM_OF_ROWS_AND_COL)
        increaseFieldValueIfExists(bombRow + 1, bombColumn);

}

void Board::increaseFieldValueIfExists(int row, int column){
    Field* field = getFieldIfExists(Coordinate(row, column));
    if(field != nullptr){
        if(field->getStatus() != FieldStatus::BOMB)
            field->setValue(field->getValue() + 1);
    }
}

Field* Board::getFieldIfExists(Coordinate c){
    for(std::list<Field*>::iterator it = fields.begin(); it != fields.end(); ++it){
        if((*(*it)->getCoordinates()) == c)
            return (*it);
    }

    return nullptr;
}
