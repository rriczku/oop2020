//
// Created by student on 12/9/20.
//

#include "factory/gui/ButtonGnomeWidget.h"
factory::gui::ButtonGnomeWidget::ButtonGnomeWidget(int gnomeVersion):gnomeVersion(gnomeVersion){}

void factory::gui::ButtonGnomeWidget::draw()
{
    std::cout<<"factory::gui::ButtonGnomeWidget{gnomeVersion: "<<gnomeVersion<<"}"<<std::endl;
}