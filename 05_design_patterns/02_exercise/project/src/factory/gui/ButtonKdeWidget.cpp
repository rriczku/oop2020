//
// Created by student on 12/8/20.
//

#include "factory/gui/ButtonKdeWidget.h"

factory::gui::ButtonKdeWidget::ButtonKdeWidget(int KdeVersion):KdeVersion(KdeVersion){}

void factory::gui::ButtonKdeWidget::draw()
{
    std::cout<<"factory::gui::ButtonKdeWidget{KdeVersion: "<<KdeVersion<<"}"<<std::endl;
}