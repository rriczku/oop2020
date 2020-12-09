//
// Created by student on 12/8/20.
//
#pragma once
#include <memory>
#include <iostream>
namespace factory
{
    namespace gui {
        class Widget {
        public:
            virtual ~Widget() = default;
            virtual void draw()=0;
        };
    }
}

