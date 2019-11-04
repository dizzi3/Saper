#ifndef BOARD_H
#define BOARD_H

#include <list>
#include "Coordinate.h"
#include "Field.h"

#define NUM_OF_ROWS_AND_COL 12
#define BOMBS 40

class Board{

public:
    Board();

    std::list<Field*> getFields();
    void generateBoard();

private:
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
