#ifndef LAYOUTGENERATOR_H
#define LAYOUTGENERATOR_H

#include <QGridLayout>

class LayoutGenerator{

public:
    static QGridLayout* generate(QWidget* widget, int numberOfRows);

};

#endif // LAYOUTGENERATOR_H
