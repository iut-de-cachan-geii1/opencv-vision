//  Copyright (c) 2021 Antoine Tran Tan
//

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "opencvthread.h"

MainWindow::MainWindow(int argc, char *argv[], QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), t(new OpenCVThread(argc, argv))
{
    ui->setupUi(this);

    connect(
        t,
        &OpenCVThread::resultReady,
        this,
        [this](int result)
        {
            qDebug() << "OpenCV thread has returned" << result << "to the main thread.";
        });

    t->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
