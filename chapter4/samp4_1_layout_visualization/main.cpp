// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#include "mainwindow.h"

#include <QApplication>

auto main(int argc, char *argv[]) -> int {
    const QString str = "Hello Qt"; // const char*类型初始化str
    qDebug() << str.at(7);          // 't'
    QString str_chinese = "你好，世界";
    qDebug() << str_chinese.at(1); // '\u597d' -> '好'

    str_chinese[3] = QChar(0x9752);           // ‘青’，使用构造函数
    str_chinese[4] = QChar::fromUcs2(0x5c9b); // ‘岛’，使用静态函数
    qDebug() << str_chinese;                  // "你好，青岛"

    // str_chinese[3] = QChar('青'); // 超过Latin1编码范围
    // qDebug() << str_chinese;     // 编译错误

    // str_chinese[4] = QChar::fromUcs2('岛'); // 错误，将UTF-8字符传给UTF-16形参
    // qDebug() << str_chinese;               // "你好，青늛"

    str_chinese.replace(str_chinese[4], "海");
    qDebug() << str_chinese; // "你好，青海"

    const QString str_material = "河湖";
    const QChar   str_He       = QChar::fromUcs2(str_material[0].unicode()); // 获取“河”的UTF-16编码，再构造一个QChar
    const auto    str_Hu       = QChar(str_material[1].unicode());
    QString       str_example  = "他们来自河南与河北";
    for (auto &i : str_example) {
        if (i == str_He) { // 逻辑比较
            i = str_Hu;
        }
    }
    qDebug() << str_example; // "他们来自湖南与湖北"

    QApplication a(argc, argv);
    MainWindow   w;
    w.show();
    return QApplication::exec();
}
