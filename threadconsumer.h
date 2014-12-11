#ifndef THREADCONSUMER_H
#define THREADCONSUMER_H

#include <QThread>

class ThreadConsumer : public QThread
{
    Q_OBJECT
public:
    explicit ThreadConsumer(QObject *parent = 0);
    void Stop();

protected:
    void run();

signals:
    void onUpdCons(const QString& msg);

public slots:

private:
    volatile bool m_Stopped;
private slots:
    void Reset();
};

#endif // THREADCONSUMER_H
