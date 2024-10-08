// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#include "test.hpp"
#include "../ui/mainwindow.h"

#include <QApplication>

auto main(int argc, char *argv[]) -> int {
    test_qstring_and_qchar();
    QApplication a(argc, argv);
    MainWindow   w;
    w.show();
    return QApplication::exec();
}
