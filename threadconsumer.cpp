#include "threadconsumer.h"
#include "buffershared.h"
#include <QDebug>

ThreadConsumer::ThreadConsumer(QObject *parent) :
    QThread(parent),
    m_Stopped(false)
{
    connect(this, SIGNAL(started()), this, SLOT(Reset()));
    connect(this, SIGNAL(finished()), this, SLOT(Reset()));
}

void ThreadConsumer::run()
{
    while (!m_Stopped)
    {
        // this ensures that we will exit this loop
        // whether the button stop is clicked
        // or the main window is closed
        if (m_Stopped)
            break;

        if (BufferShared::AcquireSemPop())
        {
            if (m_Stopped)
                break;

            QString msg = tr("Consumer: %1").arg(BufferShared::GetInstance()->getStringFromBuffer());
            BufferShared::ReleaseSemPush();

            emit onUpdCons(msg);
        }

        if (m_Stopped)
            break;

        msleep(50);
    }
}

void ThreadConsumer::Stop()
{
    m_Stopped = true;
    // release the semaphore to ensure
    // the exit from the infinite loop
    // in the run() method
    BufferShared::ReleaseSemPop();
}

void ThreadConsumer::Reset()
{
    m_Stopped = false;
}
