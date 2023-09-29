//  Copyright (c) 2023 Antoine TRAN TAN
//  Copyright (c) 2020 Victor BOUVARD
//  Copyright (c) 2011 Philipp Wagner
//

#include <QApplication>
#include <QThread>
#include <QObject>
#include "mainwindow.h"
#include "opencvthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QThread *t = new OpenCVThread(argc, argv);

    t->start();
    w.show();

    // QObject::connect(
    //     t,
    //     &OpenCVThread::resultReady,
    //     [&a](int result) {
    //         qDebug() << "OpenCV thread has returned " << result << " to the main thread.";
    //     });

    return QApplication::exec();
}
