// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'learning' project.
// This program is called: 'test'.

#include "test.hpp"

void TestItems() {
    // TestAsprintf();
    // TestArg();
    TestSetNum();
}

void TestAsprintf() {
    // 格式化字符串，语法类似C语言
    const QString str1 = QString::asprintf("Year=%d\tMonth=%2d\tDay=%2d\n", 2024, 10, 17);
    const QString China = "中国";
    // 字符串本身允许使用中文，但是使用%s替换文本时，该文本仅限于UTF-8的编码，所以需要一个编码步骤。
    const QString str2 = QString::asprintf("你好，%s\n", China.toLocal8Bit().data());
    // const QString    str2  = QString::asprintf("你好，%s\n", China); // 出现乱码，且不能用QString替换为char*类型
    constexpr double pi = M_PI;
    const QString str3 = QString::asprintf("%.10f\n", pi);

    qDebug() << str1 << str2 << str3;
}

void TestArg() {
    constexpr int year = 2024, month = 10, day = 7;
    constexpr int base = 10; // 默认为10进制
    constexpr QChar ch('0'); // 用于填充字符，默认为空格
    const QString China("中国");
    // day值填充到2位，不足前面补0；占位符出现顺序可以打乱
    // 2024年10月07日
    const auto str1 = QString("%1年%3月%2日").arg(year).arg(day, 2, base, ch).arg(month);
    // 可以直接使用汉字
    const auto str2 = QString("你好，%1").arg(China);
    // 可以将浮点数转换为字符串
    // pi=3.14159265e+00
    const auto str3 = QString("pi=%1").arg(M_PI, 0, 'e', 8);
    qDebug() << str1;
    qDebug() << str2;
    qDebug() << str3;
}

void TestSetNum() {
    constexpr double num = 1234.56789;
    QString str;
    qDebug("num=%f", num); // 1234.567890
    str.setNum(num, 'f', 5); // 小数点后5位【以自然计数法显示】1234.56789
    qDebug("str=%s", str.toLocal8Bit().data());
    str.setNum(num, 'E', 5); // 基数的小数点后5位【以科学计数法显示】1.23457E+03
    qDebug("str=%s", str.toLocal8Bit().data());
    str.setNum(num, 'g', 5); // 整数和小数总共5位【以自然计数法显示】1234.6
    qDebug("str=%s", str.toLocal8Bit().data());
    str.setNum(num, 'G', 3); // 整数小数总共3位【以自然计数法显示】1.23E+03
    qDebug("str=%s", str.toLocal8Bit().data());
}
