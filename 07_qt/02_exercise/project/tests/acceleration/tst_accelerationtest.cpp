#include <QtTest>

#include "acceleration.h"
#include "displacement.h"
class AccelerationTest : public QObject
{
    Q_OBJECT


private slots:
    void aTest()
    {
        Acceleration a{};
        Displacement d{};

        QObject::connect(&d,SIGNAL(change(double)),&a,SLOT(onChange(double)));

        d.set(10);
        d.set(11);
        d.set(13);
        QVERIFY(a.get()==1);
    }
};


QTEST_APPLESS_MAIN(AccelerationTest)

#include "tst_accelerationtest.moc"
