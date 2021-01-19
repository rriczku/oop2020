#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "counter.h"
#include "speed.h"
#include "acceleration.h"
#include "displacement.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Counter>("pl.gwizdz", 1, 0, "Counter");
    qmlRegisterType<Speed>("pl.jrychu",1,0,"Speed");
    qmlRegisterType<Acceleration>("pl.jrychu",1,0,"Acceleration");
    qmlRegisterType<Displacement>("pl.jrychu",1,0,"Displacement");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    auto displacement=engine.rootObjects().first()->findChild<Displacement*>();
    displacement->initialize(0);

    return app.exec();
}
