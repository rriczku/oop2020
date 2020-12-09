//
// Created by student on 12/8/20.
//

#include "factory/gui/ListKdeWidget.h"


factory::gui::ListKdeWidget::ListKdeWidget(int KdeVersion) : kdeVersion(KdeVersion){}

void factory::gui::ListKdeWidget::draw()
{
    std::cout << "factory::gui::ListKdeWidget{KdeVersion: "<< kdeVersion<<"}"<<std::endl;
}