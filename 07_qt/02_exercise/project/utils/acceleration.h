#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT
public:
    explicit Acceleration(QObject *parent = nullptr);
    double get();

private:
        bool hasFirstValue;
        bool hasSecondValue;
        bool hasThirdValue;
        double firstValue;
        double secondValue;
        double thirdValue;

public slots:
    void onChange(double v);

};

#endif // ACCELERATION_H
