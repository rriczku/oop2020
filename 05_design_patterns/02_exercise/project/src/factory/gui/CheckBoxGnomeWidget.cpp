//
// Created by student on 12/8/20.
//

#include "factory/gui/CheckBoxGnomeWidget.h"
factory::gui::CheckBoxGnomeWidget::CheckBoxGnomeWidget(int gnomeVersion):gnomeVersion(gnomeVersion){}

void factory::gui::CheckBoxGnomeWidget::draw()
{
    std::cout<<"factory::gui::CheckBoxGnomeWidget{gnomeVersionVersion: "<<gnomeVersion<<"}"<<std::endl;
}