#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
     m_thConsumer(new ThreadConsumer(this)),
     m_thProducer(new ThreadProducer(this))
{
    ui->setupUi(this);

    connect(ui->btnThread1, SIGNAL(clicked()),
            this, SLOT(thProducer_StartStop()));
    connect(ui->btnThread2, SIGNAL(clicked()),
            this, SLOT(thConsumer_StartStop()));
    connect(m_thProducer, SIGNAL(onUpdProd(const QString&)),
            this, SLOT(txtLog_Append(const QString&)));
    connect(m_thConsumer, SIGNAL(onUpdCons(const QString&)),
            this, SLOT(txtLog_Append(const QString&)));
}

MainWindow::~MainWindow()
{
    m_thProducer->Stop();
    m_thConsumer->Stop();

    m_thProducer->wait();
    m_thConsumer->wait();

    delete ui;
}

void MainWindow::thProducer_StartStop()
{
    if (m_thProducer->isRunning())
    {
        m_thProducer->Stop();
        ui->btnThread1->setText("Start Producer");
    }
    else
    {
        m_thProducer->start();
        ui->btnThread1->setText("Stop Producer");
    }
}

void MainWindow::txtLog_Append(const QString &msg)
{
    ui->txtLog->appendPlainText(msg);
}

void MainWindow::thConsumer_StartStop()
{
    if (m_thConsumer->isRunning())
    {
        m_thConsumer->Stop();
        ui->btnThread2->setText("Start Consumer");
    }
    else
    {
        m_thConsumer->start();
        ui->btnThread2->setText("Stop Consumer");
    }
}

