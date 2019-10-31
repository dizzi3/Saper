#ifndef STYLEDGRIDLAYOUT_H
#define STYLEDGRIDLAYOUT_H

#include <QGridLayout>

class StyledGridLayout : public QGridLayout{

private:
    StyledGridLayout(QWidget* widget);

public:
    static StyledGridLayout* instance(QWidget* widget);

};

#endif // STYLEDGRIDLAYOUT_H
