#include "Board.h"
#include <QtMath>
#include "Field.h"

Board::Board(){
    numberOfAllFields = (int)qPow(NUM_OF_ROWS_AND_COL, 2);
}

std::list<Field*> Board::getFields(){
    return this->fields;
}

void Board::uncoverAllEmptyFieldsAround(Coordinate *coordinate){

    int column = coordinate->getColumn();
    int row = coordinate->getRow();

    if(column - 1 >= 0){
        uncoverIfExists(row, column - 1);

        if(row - 1 >= 0)
            uncoverIfExists(row - 1, column - 1);

        if(row + 1 < NUM_OF_ROWS_AND_COL)
            uncoverIfExists(row + 1, column - 1);
    }

    if(column + 1 < NUM_OF_ROWS_AND_COL){
        uncoverIfExists(row, column + 1);

        if(row - 1 >= 0)
            uncoverIfExists(row - 1, column + 1);

        if(row + 1 < NUM_OF_ROWS_AND_COL)
            uncoverIfExists(row + 1, column + 1);
    }

    if(row - 1 >= 0)
        uncoverIfExists(row - 1, column);

    if(row + 1 < NUM_OF_ROWS_AND_COL)
        uncoverIfExists(row + 1, column);


}

void Board::uncoverIfExists(int row, int column){
    Field* field = getFieldIfExists(Coordinate(row, column));

    if(field == nullptr)
        return;

    if(field->isFlagged())
        return;

    if(field->getCovered() == false)
        return;

    if(field->getStatus() == FieldStatus::BOMB)
        return;

    field->setCovered(false);
    field->onLeftClickSlot();

    if(field->getStatus() == FieldStatus::EMPTY)
        uncoverAllEmptyFieldsAround(field->getCoordinates());
}

void Board::uncoverAllBombsExcept(Field *field){

    for(std::list<Field*>::iterator it = fields.begin(); it != fields.end(); ++it){

        if((*it) == field)
            continue;

        if((*it)->getStatus() == FieldStatus::BOMB && !(*it)->isFlagged())
            (*it)->setBombIcon();
    }

}

void Board::disableAllButtons(){

    for(std::list<Field*>::iterator it = fields.begin(); it != fields.end(); ++it){

        if((*it)->isFlagged())
            (*it)->setDisabledFlagStylesheet();
        else if((*it)->getCovered())
            (*it)->setDisabledStylesheet();

        (*it)->setDisabled(true);
    }

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

        Field* field = Field::getStyledField(this);
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
}

void Board::setNonBombFieldsValues(){

    for(std::list<Coordinate>::iterator it = bombsCoordinates.begin(); it != bombsCoordinates.end(); ++it)
        updateBombSurroundingFieldsValues(&(*it));
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
        if(field->getStatus() != FieldStatus::BOMB){
            field->setValue(field->getValue() + 1);
            field->setStatus(FieldStatus::NUMBER);
        }
    }
}

Field* Board::getFieldIfExists(Coordinate c){

    for(std::list<Field*>::iterator it = fields.begin(); it != fields.end(); ++it){
        Coordinate a = *((*it)->getCoordinates());

        if(a == c)
            return (*it);
    }

    return nullptr;
}
