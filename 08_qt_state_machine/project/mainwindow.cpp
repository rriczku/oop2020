#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStateMachine>
#include <QHistoryState>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto stateMachine = new QStateMachine(this);
    auto stateUnlocked=new QState(stateMachine);
    auto stateLocked=new QState(stateMachine);
    auto stateStartup=new QState(stateUnlocked);

    auto stateOpen=new QState(stateUnlocked);
    auto stateView=new QState(stateUnlocked);
    auto stateEdit=new QState(stateUnlocked);
    auto stateSave=new QState(stateUnlocked);
    auto stateError=new QState(stateUnlocked);


    stateUnlocked->assignProperty(ui->pbToggle,"text","Lock");
    stateUnlocked->assignProperty(ui->pbOpen,"enabled",true);
    stateUnlocked->assignProperty(ui->pbSave,"enabled",true);
    stateUnlocked->assignProperty(ui->teText,"enabled",true);

    stateLocked->assignProperty(ui->pbToggle,"text","Unlock");
    stateLocked->assignProperty(ui->pbOpen,"enabled",false);
    stateLocked->assignProperty(ui->pbSave,"enabled",false);
    stateLocked->assignProperty(ui->teText,"enabled",false);

    stateStartup->assignProperty(ui->pbOpen,"enabled",true);
    stateStartup->assignProperty(ui->pbSave,"enabled",false);
    stateStartup->assignProperty(ui->teText,"enabled",false);
    stateStartup->assignProperty(ui->teText,"placeholderText","Open file to start editing...");

    stateEdit->assignProperty(ui->pbOpen,"enabled",false);
    stateEdit->assignProperty(ui->pbSave,"enabled",true);
    stateEdit->assignProperty(ui->teText,"enabled",true);

    stateView->assignProperty(ui->pbOpen,"enabled",true);
    stateView->assignProperty(ui->pbSave,"enabled",false);
    stateView->assignProperty(ui->teText,"enabled",true);

    stateError->assignProperty(ui->pbOpen,"enabled",true);
    stateError->assignProperty(ui->pbSave,"enabled",false);
    stateError->assignProperty(ui->teText,"enabled",false);
    stateError->assignProperty(ui->teText,"placeholderText","Error ocured. Open file to start editing...");

    connect(stateOpen,SIGNAL(entered()),this,SLOT(open()));
    connect(stateSave,SIGNAL(entered()),this,SLOT(save()));

    stateStartup->addTransition(ui->pbOpen,SIGNAL(clicked()),stateOpen);

    stateOpen->addTransition(this,SIGNAL(error()),stateError);
    stateOpen->addTransition(this,SIGNAL(opened()),stateView);

    stateError->addTransition(ui->pbOpen,SIGNAL(clicked()),stateOpen);

    stateSave->addTransition(this,SIGNAL(error()),stateError);
    stateSave->addTransition(this,SIGNAL(saved()),stateView);

    stateView->addTransition(ui->pbOpen,SIGNAL(clicked()),stateOpen);
    stateView->addTransition(ui->teText,SIGNAL(textChanged()),stateEdit);

    stateEdit->addTransition(ui->pbSave,SIGNAL(clicked()),stateSave);

    QHistoryState *s1h =new QHistoryState(stateUnlocked);

    stateLocked->addTransition(ui->pbToggle,SIGNAL(clicked()),s1h);
    stateUnlocked->addTransition(ui->pbToggle,SIGNAL(clicked()),stateLocked);

    stateMachine->setInitialState(stateUnlocked);
    stateUnlocked->setInitialState(stateStartup);
    stateMachine->start();
    // TODO: Create state machine
    // TODO: Create states
    // TODO: Set appropriate 'assignProperty'
    // TODO: Set state transitions including this class events and slots
    // TODO: Set initial state
    // TODO: Start state machine
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
   // fileName=QFileDialog::getOpenFileName(this,tr("Open a file"),"/home",tr("Text files (*.txt"));
    fileName=QFileDialog::getOpenFileName(this,"open a file");
        QFile file(fileName);
        if(!file.open(QIODevice::ReadWrite))
        {
            emit error();
            return;
        }
        QTextStream instream(&file);
        ui->teText->setText(instream.readAll());
        emit opened();
    // TODO: Show file dialog
    // TODO: Open selected file
    // TODO: Emit 'error' if opening failed
    // TODO: Set text and emit 'opened' if suceeded
    // TODO: Save file name in 'fileName'
}

void MainWindow::save()
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        emit error();
        return;
    }
    QTextStream stream(&file);

    stream<<ui->teText->toPlainText();
    emit saved();
   //
    // TODO: Open 'fileName' for writing
    // TODO: Emit 'error' if opening failed
    // TODO: Save file and emit 'saved' if succeeded
}

