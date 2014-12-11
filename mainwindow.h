#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "threadconsumer.h"
#include "threadproducer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    ThreadConsumer *m_thConsumer;
    ThreadProducer *m_thProducer;

private slots:
    void thConsumer_StartStop();
    void thProducer_StartStop();
    void txtLog_Append(const QString& msg);


};

#endif // MAINWINDOW_H
