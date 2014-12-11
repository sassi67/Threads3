#include "buffershared.h"

BufferShared* BufferShared::m_Instance = NULL;
QSemaphore BufferShared::m_BufferPush(BUFFER_SIZE);
QSemaphore BufferShared::m_BufferPop(0);

BufferShared* BufferShared::GetInstance()
{
    if (NULL == m_Instance)
    {
        m_Instance = new BufferShared();
    }
    return m_Instance;
}

void BufferShared::setStringInBuffer(const QString &s)
{
    if (m_IndexSet == BUFFER_SIZE)
        m_IndexSet = 0;
    m_Buffer[m_IndexSet++] = s;
}

QString BufferShared::getStringFromBuffer()
{
    if (m_IndexGet == BUFFER_SIZE)
        m_IndexGet = 0;
//    QString msg = QString("Buffer position: %1 -- %2")
//                .arg(QString::number(m_IndexGet))
//                .arg(m_Buffer[m_IndexGet++]);
    return m_Buffer[m_IndexGet++];
}

bool BufferShared::AcquireSemPush()
{
    return m_BufferPush.tryAcquire(1, 100);
}

bool BufferShared::AcquireSemPop()
{
    return m_BufferPop.tryAcquire(1, 100);
}

void BufferShared::ReleaseSemPush()
{
    m_BufferPush.release();
}

void BufferShared::ReleaseSemPop()
{
    m_BufferPop.release();
}

BufferShared::BufferShared():
    m_IndexSet(0),
    m_IndexGet(0)
{
}
