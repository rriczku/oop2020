//
// Created by student on 12/8/20.
//

#include "observer/Speed.h"

void observer::Speed::notify(float f) {

        if(!hasFirstValue)
        {
            hasFirstValue=true;
            firstValue=f;
        }
        else if(!hasSecondValue)
        {
            hasSecondValue=true;
            secondValue=f;
        }else
        {
            firstValue=secondValue;
            secondValue=f;
        }
}

float observer::Speed::get() {
    return secondValue-firstValue;
}
