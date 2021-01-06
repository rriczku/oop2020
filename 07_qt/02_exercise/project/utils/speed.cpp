#include "speed.h"
#include <QDebug>
Speed::Speed(QObject *parent) : QObject(parent)
{
    hasFirstValue=false;
    hasSecondValue=false;
    firstValue=0;
    secondValue=0;
}

void Speed::onChange(double v)
{
    if(!hasFirstValue) {
          firstValue = v;
          hasFirstValue = true;
      }
      else if(!hasSecondValue) {
          secondValue = v;
          hasSecondValue = true;
      }
      else {
          firstValue = secondValue;
          secondValue = v;
      }
}
double Speed::get()
{
    return secondValue-firstValue;
}
