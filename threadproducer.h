#ifndef THREADPRODUCER_H
#define THREADPRODUCER_H

#include <QThread>

class ThreadProducer : public QThread
{
    Q_OBJECT
public:
    explicit ThreadProducer(QObject *parent = 0);
    void Stop();

protected:
    void run();

signals:
    void onUpdProd(const QString& msg);

public slots:

private:
    enum { MAX_VALUE = 4096 };
    volatile bool m_Stopped;
    int m_IntToPrint;

    int GetIntToPrint();
private slots:
    void Reset();
};

#endif // THREADPRODUCER_H
