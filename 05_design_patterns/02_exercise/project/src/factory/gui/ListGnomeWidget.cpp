//
// Created by student on 12/8/20.
//

#include "factory/gui/ListGnomeWidget.h"
factory::gui::ListGnomeWidget::ListGnomeWidget(int gnomeVersion):gnomeVersion(gnomeVersion){}

void factory::gui::ListGnomeWidget::draw()
{
    std::cout<<"factory::gui::ListGnomeWidget{gnomeVersion: "<<gnomeVersion<<"}"<<std::endl;
}