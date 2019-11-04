#include "Field.h"

#include <QMessageBox>

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

    return field;
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
