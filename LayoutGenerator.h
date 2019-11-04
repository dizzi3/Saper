#ifndef LAYOUTGENERATOR_H
#define LAYOUTGENERATOR_H

#include <QGridLayout>
#include <list>
#include "StyledGridLayout.h"
#include "Coordinate.h"
#include "Field.h"
#include "Board.h"

class LayoutGenerator{

private:
    LayoutGenerator();

    void freeInstanceMemory();
    void addFieldsToTheLayout(StyledGridLayout* layout);

public:
    static StyledGridLayout* generate(QWidget* widget);

private:
    static LayoutGenerator* instance;
    Board* board;
};

#endif // LAYOUTGENERATOR_H
