#ifndef LAYOUTGENERATOR_H
#define LAYOUTGENERATOR_H

#include <QGridLayout>
#include <list>
#include "StyledGridLayout.h"
#include "Coordinate.h"
#include "Field.h"

#define NUM_OF_ROWS_AND_COL 8
#define BOMBS 10

class LayoutGenerator{

private:
    LayoutGenerator();
    void freeInstanceMemory();
    static LayoutGenerator* instance;

    std::list<Coordinate> bombsCoordinates;
    Coordinate generateRandomCoordinate();
    void generateBombsCoordinates();
    void setBombStatusIfFieldIsOnTheList(Field* field, Coordinate coordinates);
    bool doesBombListContain(Coordinate element);

public:
    static StyledGridLayout* generate(QWidget* widget);

private:
    int numberOfAllFields;
};

#endif // LAYOUTGENERATOR_H
