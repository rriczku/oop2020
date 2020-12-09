//
// Created by student on 12/8/20.
//

#include "factory/gui/CheckBoxKdeWidget.h"

factory::gui::CheckBoxKdeWidget::CheckBoxKdeWidget(int KdeVersion) : KdeVersion(KdeVersion) {}

void factory::gui::CheckBoxKdeWidget::draw() {

    std::cout << "factory::gui::CheckBoxKdeWidget{KdeVersion: "<<KdeVersion<<"}"<<std::endl;
}