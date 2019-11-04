#include "Field.h"

#include <QMessageBox>
#include "Board.h"

Field::Field(const Field& field){
    this->status = field.getStatus();
    this->coordinates = field.getCoordinates();
    this->value = field.getValue();
}

Field::Field() : coordinates(nullptr){}

void Field::setStatus(FieldStatus status){
    this->status = status;
}

FieldStatus Field::getStatus() const{
    return this->status;
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

Field* Field::getStyledField(){
    Field* field = new Field();

    QObject::connect(field, &Field::clicked, field, &Field::onClickSlot);

    field->setMaximumWidth(30);
    field->setMaximumHeight(30);
    field->setStatus(FieldStatus::EMPTY);
    field->setValue(0);

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

QString Field::getTextColorBasedOnValue(){
    QString stylesheet = "font-weight: bold;";

    if(NUM_OF_ROWS_AND_COL < 10)
        stylesheet.append("font-size: 15px;");
    else if(NUM_OF_ROWS_AND_COL >= 10 && NUM_OF_ROWS_AND_COL < 15)
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

void Field::onClickSlot(){

    if(getStatus() == FieldStatus::BOMB){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Title");
        msgBox.setText("You Clicked a bomb");
        msgBox.exec();
    }else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Title");
        msgBox.setText("NOT A BOMB");
        msgBox.exec();
    }

}
