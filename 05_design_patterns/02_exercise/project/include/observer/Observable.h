//
// Created by student on 12/8/20.
//

#pragma once

#include "Observer.h"
#include <set>

namespace observer{
    class Observable
    {
    public:
        void registerObserver(Observer*);
        void unregisterObserver(Observer*);

    protected:
       void notifyObservers(float);
    private:
        std::set<Observer*> observers;
    };
}
