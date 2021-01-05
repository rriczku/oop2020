#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT
public:
    explicit Speed(QObject *parent = nullptr);
    float get();
private:
    bool hasFirstValue;
    bool hasSecondValue;
    int firstValue;
    int secondValue;

public slots:
    void onChange(double v);

};

#endif // SPEED_H
