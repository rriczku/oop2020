//
// Created by student on 12/8/20.
//

#include "observer/Acceleration.h"

float observer::Acceleration::get() {
    if(hasFirstValue&&hasSecondValue&&hasThirdValue)
        return (thirdValue-secondValue)-(secondValue-firstValue);
    else if(hasFirstValue&&hasSecondValue&&!hasThirdValue)
        return secondValue-firstValue;
    else return 0;
}

void observer::Acceleration::notify(float f) {
    if(!hasFirstValue)
    {
        hasFirstValue=true;
        firstValue=f;
    }
    else if(!hasSecondValue)
    {
        secondValue=firstValue;
        hasSecondValue=true;
        firstValue=f;
    }
    else if(!hasThirdValue)
    {
        thirdValue=secondValue;
        secondValue=firstValue;
        hasThirdValue=true;
        firstValue=f;
    }
}
