#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double value READ get WRITE changed)
public:
    explicit Speed(QObject *parent = nullptr);

private:
    bool hasFirstValue;
    bool hasSecondValue;
    double firstValue;
    double secondValue;

public slots:
    void changed(double v);
    double get();

};

#endif // SPEED_H
