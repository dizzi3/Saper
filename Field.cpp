#include "Field.h"

#include <QMessageBox>
#include "Board.h"

Field::Field(const Field& field){
    this->status = field.getStatus();
    this->coordinates = field.getCoordinates();
    this->value = field.getValue();
    this->board = field.board;
    this->covered = field.covered;
}

Field::Field(Board* board) : coordinates(nullptr){
    this->board = board;
    covered = true;
}

void Field::setStatus(FieldStatus status){
    this->status = status;
}

FieldStatus Field::getStatus() const{
    return this->status;
}

void Field::setCovered(bool c){
    covered = c;
}

bool Field::getCovered(){
    return this->covered;
}

void Field::setCoordinates(Coordinate* c){
    this->coordinates = c;
}

Coordinate* Field::getCoordinates() const{
    return this->coordinates;
}

void Field::setValue(int value){
    this->value = value;
}

int Field::getValue() const{
    return this->value;
}

Field* Field::getStyledField(Board* board){
    Field* field = new Field(board);

    connect(field, &Field::clicked, field, &Field::onClickSlot);

    field->setMaximumWidth(30);
    field->setMaximumHeight(30);
    field->setStatus(FieldStatus::EMPTY);
    field->setValue(0);

    field->setCheckable(true);
    field->setCursor(Qt::PointingHandCursor);

    return field;
}

void Field::updateTextBasedOnValue(){

    if(status == FieldStatus::BOMB)
        return;

    if(value == 0){
        status = FieldStatus::EMPTY;
        return;
    }

    status = FieldStatus::NUMBER;
    setText(QString::number(value));
    setStyleSheet(getTextColorBasedOnValue());
}

void Field::setBombIcon(){
    QIcon icon;
    icon.addPixmap(QPixmap(":/icons/bomb_icon.png"), QIcon::Normal);
    icon.addPixmap(QPixmap(":/icons/bomb_icon.png"), QIcon::Disabled);

    setIcon(icon);
}

void Field::setDisabledStylesheet(){
    QString stylesheet = "background-color: #576490; border: 1.2px solid #000;";
    setStyleSheet(stylesheet);
}

QString Field::getTextColorBasedOnValue(){
    QString stylesheet = getBasicStylesheet() + "font-weight: bold;";

    if(Board::NUM_OF_ROWS_AND_COL < 10)
        stylesheet.append("font-size: 15px;");
    else if(Board::NUM_OF_ROWS_AND_COL >= 10 && Board::NUM_OF_ROWS_AND_COL < 15)
        stylesheet.append("font-size: 14px;");
    else
        stylesheet.append("font-size: 9.5px;");

    stylesheet.append("color: ");

    switch(value){

        case 1:
            return stylesheet.append("blue;");
        case 2:
            return stylesheet.append("green;");
        case 3:
            return stylesheet.append("red;");
        case 4:
            return stylesheet.append("#ff00d4");
        case 5:
            return stylesheet.append("#9900ff");
    default:
        return stylesheet.append("black;");

    }

}

QString Field::getBasicStylesheet(){
    return "background-color: #c2eaff; border: 1.2px solid #000;";
}

void Field::onClickSlot(){

    if(status == FieldStatus::EMPTY){
        setStyleSheet(getBasicStylesheet());
        board->uncoverAllEmptyFieldsAround(coordinates);
    }else if(status == FieldStatus::NUMBER)
        updateTextBasedOnValue();
    else{
        board->disableAllButtons();
        setBombIcon();
        setStyleSheet(":disabled{background-color: #ff1212; border: 1.2px solid #000}");
        board->uncoverAllBombsExcept(this);

    }

    covered = false;
    setCursor(Qt::ArrowCursor);
}
