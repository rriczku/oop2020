#include "acceleration.h"
#include <QDebug>
Acceleration::Acceleration(QObject *parent) : QObject(parent)
{
    hasFirstValue=false;
    hasSecondValue=false;
    hasThirdValue=false;
    firstValue=0;
    secondValue=0;
    thirdValue=0;
}
void Acceleration::onChange(double v)
{
    if(!hasFirstValue)
        {
            hasFirstValue=true;
            firstValue=v;
        }
        else if(!hasSecondValue)
        {
            secondValue=firstValue;
            hasSecondValue=true;
            firstValue=v;
        }
        else if(!hasThirdValue)
        {
            thirdValue=secondValue;
            secondValue=firstValue;
            hasThirdValue=true;
            firstValue=v;
        }
}
double Acceleration::get()
{
    if(hasFirstValue&&hasSecondValue&&hasThirdValue)
            return (thirdValue-secondValue)-(secondValue-firstValue);
        else if(hasFirstValue&&hasSecondValue&&!hasThirdValue)
            return secondValue-firstValue;
        else return 0;
}
