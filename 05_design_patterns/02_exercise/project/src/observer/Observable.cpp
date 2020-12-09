//
// Created by student on 12/8/20.
//

#include "observer/Observable.h"

void observer::Observable::registerObserver(observer::Observer* o) {
    this->observers.insert(o);
}

void observer::Observable::unregisterObserver(observer::Observer* o) {
    this->observers.erase(o);
}

void observer::Observable::notifyObservers(float f) {
    for(Observer* observer:observers)
    {
        observer->notify(f);
    }
}
