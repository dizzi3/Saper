#include "Field.h"

FieldStatus Field::getStatus(){
    return this->status;
}

void Field::setStatus(FieldStatus status){
    this->status = status;
}
