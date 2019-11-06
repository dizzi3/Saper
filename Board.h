#ifndef BOARD_H
#define BOARD_H

#include <list>
#include "Coordinate.h"

#define NUM_OF_ROWS_AND_COL 13
#define BOMBS 22

class Field;

class Board{

public:
    Board();

    std::list<Field*> getFields();
    void uncoverAllEmptyFieldsAround(Coordinate* coordinate);

    void generateBoard();

private:
    void uncoverIfExists(int row, int column);
    void generateBombsCoordinates();
    Coordinate* generateRandomCoordinate(std::mt19937* eng);
    void generateFields();
    bool doesBombListContain(Coordinate element);
    void setBombStatus(Field* field);
    void setNonBombFieldsValues();
    void updateBombSurroundingFieldsValues(Coordinate* bombCoordinate);
    void increaseFieldValueIfExists(int row, int column);
    Field* getFieldIfExists(Coordinate c);

    std::list<Coordinate> bombsCoordinates;
    std::list<Field*> fields;
    int numberOfAllFields;
};

#endif // BOARD_H
