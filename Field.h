#ifndef FIELD_H
#define FIELD_H

#include <QPushButton>
#include "FieldStatus.h"

class Field : public QPushButton{

private:
    FieldStatus status;

public:
    FieldStatus getStatus();
    void setStatus(FieldStatus status);

    static Field* getStyledField();

public slots:
    void onClickSlot();

};

#endif // FIELD_H
