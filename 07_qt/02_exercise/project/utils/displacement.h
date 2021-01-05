#ifndef DISPLACEMENT_H
#define DISPLACEMENT_H

#include <QObject>

class Displacement : public QObject
{
    Q_OBJECT
public:
    explicit Displacement(QObject *parent = nullptr);
    void set(double v);

private:
       double value;

signals:
       void change(double v);
};

#endif // DISPLACEMENT_H
