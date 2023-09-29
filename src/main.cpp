//  Copyright (c) 2023 Antoine TRAN TAN
//  Copyright (c) 2020 Victor BOUVARD
//  Copyright (c) 2011 Philipp Wagner
//

#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(argc,argv);

    w.show();

    return QApplication::exec();
}
