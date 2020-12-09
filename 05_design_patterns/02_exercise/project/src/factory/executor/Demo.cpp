//
// Created by student on 12/8/20.
//

#include "factory/executor/Demo.h"
factory::executor::Demo::Demo(std::shared_ptr<executor::CoreFactory> factory) : factory(std::move(factory)){}

void factory::executor::Demo::run(std::string type)
{
    auto widget = factory->create(std::move(type));
    widget->execute();
}