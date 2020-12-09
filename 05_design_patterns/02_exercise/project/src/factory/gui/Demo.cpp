//
// Created by student on 12/8/20.
//

#include "factory/gui/Demo.h"

factory::gui::Demo::Demo(std::shared_ptr<gui::WidgetFactory> factory) : factory(std::move(factory)){}

void factory::gui::Demo::run(std::string type)
{
    auto widget = factory->create(std::move(type));
    widget->draw();
}