#include "threadproducer.h"
#include "buffershared.h"
#include <QDebug>

ThreadProducer::ThreadProducer(QObject *parent) :
    QThread(parent),
    m_Stopped(false),
    m_IntToPrint(0)
{
    connect(this, SIGNAL(started()), this, SLOT(Started()));
//    connect(this, SIGNAL(finished()), this, SLOT(Stop()));
}

void ThreadProducer::run()
{
    while (!m_Stopped)
    {
        // this ensures that we will exit this loop
        // whether the button stop is clicked
        // or the main window is closed
//        if (m_Stopped)
//            break;

        if (BufferShared::AcquireSemPush())
        {
            if (m_Stopped)
                break;

            QString msg = tr("Producer: index: %1").arg(QString::number(GetIntToPrint()));
            BufferShared::GetInstance()->setStringInBuffer(msg);
            //qDebug() << msg;
            BufferShared::ReleaseSemPop();
            emit onUpdProd(msg);
        }

//        if (m_Stopped)
//            break;

        msleep(50);
    }
}
void ThreadProducer::Stop()
{
    m_Stopped = true;
    // release the semaphore to ensure
    // the exit from the infinite loop
    // in the run() method
    BufferShared::ReleaseSemPush();
}

int ThreadProducer::GetIntToPrint()
{
    if (m_IntToPrint == MAX_VALUE)
        m_IntToPrint = 0;
    return m_IntToPrint++;
}

void ThreadProducer::Started()
{
    m_Stopped = false;
}
