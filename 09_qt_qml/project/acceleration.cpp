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
void Acceleration::changed(double v)
{
    if(!hasFirstValue)
        {
            hasFirstValue=true;
            firstValue=v;
        }
        else if(!hasSecondValue)
        {
            secondValue=v;
            hasSecondValue=true;
            return;
        }
        else if(!hasThirdValue)
        {
            thirdValue=v;
            hasThirdValue=true;
        }
        else
        {
            firstValue=secondValue;
            secondValue=thirdValue;
            thirdValue=v;
        }

}
double Acceleration::get()
{
    if(hasFirstValue&&hasSecondValue&&hasThirdValue)
    {
        qDebug()<<((thirdValue-secondValue)-(secondValue-firstValue));
        return ((thirdValue-secondValue)-(secondValue-firstValue));
    }
    qDebug("0");
    return 0;
}
