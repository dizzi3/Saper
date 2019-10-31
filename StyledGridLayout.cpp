#include "StyledGridLayout.h"

StyledGridLayout::StyledGridLayout(QWidget* widget) : QGridLayout(widget){}

StyledGridLayout* StyledGridLayout::instance(QWidget* widget){
    StyledGridLayout* layout = new StyledGridLayout(widget);

    layout->setHorizontalSpacing(2);
    layout->setVerticalSpacing(2);

    return layout;
}
