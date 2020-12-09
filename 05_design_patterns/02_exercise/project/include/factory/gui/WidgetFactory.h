//
// Created by student on 12/8/20.
//
#pragma once
#include "Widget.h"

namespace factory{
    namespace gui{

        class WidgetFactory{
        public:
            virtual ~WidgetFactory()=default;

            virtual std::shared_ptr<Widget> create(std::string type)=0;
        };
    }
}