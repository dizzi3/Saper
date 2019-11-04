#ifndef FIELD_H
#define FIELD_H

#include <QPushButton>
#include "FieldStatus.h"
#include "Coordinate.h"

class Field : public QPushButton{

public:
    Field(Coordinate* c) : coordinates(c){}
    Field(const Field& field);

private:
    Field();
    FieldStatus status;
    Coordinate* coordinates;
    int value;

public:
    void setStatus(FieldStatus status);
    FieldStatus getStatus() const;

    void setCoordinates(Coordinate* c);
    Coordinate* getCoordinates() const;

    void setValue(int value);
    int getValue() const;

    static Field* getStyledField();

private slots:
    void onClickSlot();

};

#endif // FIELD_H
