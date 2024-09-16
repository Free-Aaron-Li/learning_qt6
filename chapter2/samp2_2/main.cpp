// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#include "dialog.h"

#include <QApplication>

int
main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Dialog       w;
    w.show();
    return a.exec();
}
