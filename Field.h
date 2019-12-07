#ifndef FIELD_H
#define FIELD_H

#include <QPushButton>
#include "FieldStatus.h"
#include "Coordinate.h"
#include "Board.h"

class Field : public QPushButton{

public:
    Field(Coordinate* c, Board* board) : coordinates(c){this->board = board; covered = true;}
    Field(const Field& field);

private:
    Field(Board* board);
    FieldStatus status;
    Coordinate* coordinates;
    int value;
    bool covered;

    Board* board;

public:
    void setStatus(FieldStatus status);
    FieldStatus getStatus() const;

    void setCoordinates(Coordinate* c);
    Coordinate* getCoordinates() const;

    void setValue(int value);
    int getValue() const;

    void setCovered(bool covered);
    bool getCovered();

    static Field* getStyledField(Board* board);
    void updateTextBasedOnValue();

    void setBombIcon();
    void setDisabledStylesheet();

private:
    QString getTextColorBasedOnValue();
    QString getBasicStylesheet();

private slots:
    void onClickSlot();

};

#endif // FIELD_H
