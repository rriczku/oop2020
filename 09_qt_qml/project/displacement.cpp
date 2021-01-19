#include "displacement.h"
#include <QDebug>
Displacement::Displacement(QObject *parent) : QObject(parent)
{
    value=0;
}

void Displacement::set(double v)
{
    value=v;
    emit changed(v);
}
double Displacement::get()
{
    return value;
}
 void Displacement::initialize(double v)
 {
     value=v;
     emit changed(value);
 }
