#include "displacement.h"

Displacement::Displacement(QObject *parent) : QObject(parent)
{
    value=0;
}

void Displacement::set(double v)
{
    value=v;
    emit change(value);
}
