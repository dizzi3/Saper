#ifndef BOARD_H
#define BOARD_H

#include <list>
#include "Coordinate.h"
#include "Field.h"

#define NUM_OF_ROWS_AND_COL 8
#define BOMBS 10

class Board{

public:
    Board();

    std::list<Field*> getFields();
    void generateBoard();

private:
    void generateBombsCoordinates();
    Coordinate* generateRandomCoordinate(std::mt19937* eng);
    void generateFields();
    void setBombStatusIfFieldIsOnList(Field* field, Coordinate coordinates);
    bool doesBombListContain(Coordinate element);

    std::list<Coordinate> bombsCoordinates;
    std::list<Field*> fields;
    int numberOfAllFields;
};

#endif // BOARD_H
