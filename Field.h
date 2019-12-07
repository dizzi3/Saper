#ifndef FIELD_H
#define FIELD_H

#include <QPushButton>
#include "FieldStatus.h"
#include "Coordinate.h"
#include "Board.h"
#include <QMouseEvent>

class Field : public QPushButton{

Q_OBJECT

public:
    Field(Coordinate* c, Board* board) : coordinates(c){this->board = board; covered = true;}
    Field(const Field& field);

private:
    Field(Board* board);
    FieldStatus status;
    Coordinate* coordinates;
    int value;
    bool covered;
    bool flagged;

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

    bool isFlagged();

    static Field* getStyledField(Board* board);
    void updateTextBasedOnValue();

    void setBombIcon();
    void setDisabledStylesheet();
    void setDisabledFlagStylesheet();

private:
    QString getTextColorBasedOnValue();
    QString getBasicStylesheet();
    void setFlaggedStyle();
    void setDefaultStyle();

public slots:
    void onLeftClickSlot();

private slots:
    void onRightClickSlot();
    void mousePressEvent(QMouseEvent *e);

signals:
    void leftMouseButtonClicked();
    void rightMouseButtonClicked();

};

#endif // FIELD_H
