//
// Created by student on 12/8/20.
//

#include "observer/Displacement.h"

void observer::Displacement::set(float f) {
    this->value=f;
    notifyObservers(this->value);
}
