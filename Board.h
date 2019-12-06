#ifndef BOARD_H
#define BOARD_H

#include <list>
#include "Coordinate.h"
#include "StyledGridLayout.h"

class Field;

class Board{

public:
    static const int NUM_OF_ROWS_AND_COL = 14;
    static const int BOMBS = 25;

    Board();

    std::list<Field*> getFields();
    void uncoverAllEmptyFieldsAround(Coordinate* coordinate);
    void uncoverAllBombsExcept(Field* field);

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
    StyledGridLayout* gridLayout;
};

#endif // BOARD_H
