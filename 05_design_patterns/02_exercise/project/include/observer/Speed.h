//
// Created by student on 12/8/20.
//

#pragma once
#include "Observer.h"
namespace observer{
    class Speed:public Observer
    {
    public:
        float get();
        void notify(float) override;
    private:
        bool hasFirstValue;
        bool hasSecondValue;
        float firstValue;
        float secondValue;
    };
}