#include "mainwindow.h"
#include <QApplication>
#include "buffershared.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    BufferShared *buf = BufferShared::GetInstance();
//    buf->setStringInBuffer("Hello World!");
//    qDebug() << buf->getStringFromBuffer();

    return a.exec();
}
