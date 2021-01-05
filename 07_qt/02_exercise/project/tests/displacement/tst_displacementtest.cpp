#include <QtTest>

#include "displacement.h"

class DisplacementTest : public QObject
{
    Q_OBJECT


private slots:
    void dTest()
    {
        Displacement d{};
        QSignalSpy s(&d,SIGNAL(change(double)));
        d.set(1);
        QList<QVariant> t=s.takeFirst();
        QVERIFY(t.at(0).type()==QVariant::Double);
    }

};



QTEST_APPLESS_MAIN(DisplacementTest)

#include "tst_displacementtest.moc"

