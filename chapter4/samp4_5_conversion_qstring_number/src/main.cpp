// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#include "test.hpp"
#include "widget.h"

#include <QApplication>

auto
main(int argc, char *argv[]) -> int {
    QApplication a(argc, argv);
    Widget       w;
    w.show();
    // 测试项
    TestItems();
    return QApplication::exec();
}
