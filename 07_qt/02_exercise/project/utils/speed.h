#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT
public:
    explicit Speed(QObject *parent = nullptr);
    double get();
private:
    bool hasFirstValue;
    bool hasSecondValue;
    double firstValue;
    double secondValue;

public slots:
    void onChange(double v);

};

#endif // SPEED_H
