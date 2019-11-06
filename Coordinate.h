#ifndef COORDINATE_H
#define COORDINATE_H

#include <QPoint>

class Coordinate : public QPoint{

public:
    Coordinate(int row, int col);

    static Coordinate* getCoordinateBasedOnIndex(int index);

    bool operator == (Coordinate const obj);

    int getRow();
    int getColumn();

};

#endif // COORDINATE_H
