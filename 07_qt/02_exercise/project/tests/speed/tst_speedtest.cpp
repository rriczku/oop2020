#include <QtTest>
#include "speed.h"
#include "displacement.h"

class SpeedTest : public QObject
{
    Q_OBJECT


private slots:
    void sTest()
    {
        Displacement d{};
        Speed s{};

        QObject::connect(&d,SIGNAL(change(double)),&s,SLOT(onChange(double)));

        d.set(10);
        d.set(11);
        d.set(13);
        QVERIFY(s.get()==2);

    }
};



QTEST_APPLESS_MAIN(SpeedTest)

#include "tst_speedtest.moc"

