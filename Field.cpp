#include "Field.h"

#include <QMessageBox>

FieldStatus Field::getStatus(){
    return this->status;
}

void Field::setStatus(FieldStatus status){
    this->status = status;
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

Field* Field::getStyledField(){
    Field* field = new Field();

    QObject::connect(field, &Field::clicked, field, &Field::onClickSlot);

    field->setMaximumWidth(30);
    field->setMaximumHeight(30);

    return field;
}
