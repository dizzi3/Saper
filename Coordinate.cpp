#include "Coordinate.h"
#include "LayoutGenerator.h"

Coordinate::Coordinate(int row, int col) : QPoint(row, col){}

Coordinate* Coordinate::getCoordinateBasedOnIndex(int index){

    int row = (int)(index/ NUM_OF_ROWS_AND_COL);
    int column = (int)(index % NUM_OF_ROWS_AND_COL);

    return new Coordinate(row, column);
}

bool Coordinate::operator == (Coordinate const obj){
    if(obj.x() == this->x() && obj.y() == this->y())
        return true;

    return false;
}

int Coordinate::getRow(){
    return this->x();
}

int Coordinate::getColumn(){
    return this->y();
}
