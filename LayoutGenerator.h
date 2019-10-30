#ifndef LAYOUTGENERATOR_H
#define LAYOUTGENERATOR_H

#include <QGridLayout>
#include <list>

#define NUM_OF_ROWS_AND_COL 8
#define BOMBS 10

class LayoutGenerator{

public:
    static std::list<int> bombsPositions;
    static void generateBombsPositions();
    static bool bombListContains(int element);

public:
    static QGridLayout* generate(QWidget* widget);

};

#endif // LAYOUTGENERATOR_H
