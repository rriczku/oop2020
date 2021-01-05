#include <QCoreApplication>
#include <QDebug>
#include "utils.h"
#include "acceleration.h"
#include "speed.h"
#include "displacement.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Displacement d{};
    Speed s{};
    Acceleration ac{};

    QObject::connect(&d,SIGNAL(change(double)),&s,SLOT(onChange(double)));

    QObject::connect(&d,SIGNAL(change(double)),&ac,SLOT(onChange(double)));

    d.set(10);
    d.set(11);
    d.set(13);
    qDebug()<<"Acceleration: "<<ac.get() <<"Speed"<<s.get();

    return a.exec();
}
