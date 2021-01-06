#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "utils.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    d=new Displacement(this);
    s=new Speed(this);
    ac=new Acceleration(this);

    QObject::connect(d,SIGNAL(change(double)),s,SLOT(onChange(double)));
    QObject::connect(d,SIGNAL(change(double)),ac,SLOT(onChange(double)));

    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double value=ui->lineEdit->text().toFloat();
    d->set(value);
    ui->lcdNumber->display(s->get());
    ui->lcdNumber_2->display(ac->get());
}
