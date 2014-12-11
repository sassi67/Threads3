#ifndef BUFFERSHARED_H
#define BUFFERSHARED_H

#include <QString>
#include <QSemaphore>

static const int BUFFER_SIZE = 4096;

class BufferShared
{
public:
    static BufferShared *GetInstance();

    void setStringInBuffer(const QString& s);
    QString getStringFromBuffer();

    static bool AcquireSemPush();
    static bool AcquireSemPop();
    static void ReleaseSemPush();
    static void ReleaseSemPop();

private:
    BufferShared();
    BufferShared(const BufferShared& rhs);
    BufferShared& operator=(const BufferShared& rhs);

    static BufferShared *m_Instance;

    QString m_Buffer[BUFFER_SIZE];
    int m_IndexSet;
    int m_IndexGet;

    static QSemaphore m_BufferPush;
    static QSemaphore m_BufferPop;
};

#endif // BUFFERSHARED_H
