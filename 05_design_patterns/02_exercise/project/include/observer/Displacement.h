//
// Created by student on 12/8/20.
//
#pragma once
#include "Observable.h"
namespace observer {
    class Displacement : public Observable {
    public:
        void set(float);

    private:
        float value;
    };
}


