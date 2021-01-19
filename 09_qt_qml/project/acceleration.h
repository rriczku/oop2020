#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double value READ get WRITE changed)
public:
    explicit Acceleration(QObject *parent = nullptr);


private:
        bool hasFirstValue;
        bool hasSecondValue;
        bool hasThirdValue;
        double firstValue;
        double secondValue;
        double thirdValue;

public slots:
    void changed(double v);
    double get();

};

#endif // ACCELERATION_H
