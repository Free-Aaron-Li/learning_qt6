// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    ui->lineEdit_char_input->setMaxLength(1); // 限制仅能输入一个字符
}

Widget::~Widget() { delete ui; }

void
Widget::on_pushButton_unicode_conversion_clicked() const {
    if (const QString input_string = ui->lineEdit_string_input->text(); input_string.isEmpty()) { // 错误判断
        QMessageBox::warning(nullptr, "警告", "无内容！", QMessageBox::Yes);
    } else {
        ui->plainTextEdit->clear();                    // 清空文本框
        for (auto ch : input_string) {                 // 遍历字符串
            const auto    unicode_char = ch.unicode(); // 转为Unicode码
            const QString info
                    = QString(ch) + QString::asprintf("\t，Unicode编码=0x%X", unicode_char); // 表示十六进制(大写）
            ui->plainTextEdit->appendPlainText(info);                                     // 自动换行输出字符串
        }
    }
}

void
Widget::on_pushButton_char_judgement_clicked() const {
    if (const QString input_char = ui->lineEdit_char_input->text(); input_char.isEmpty()) { // 错误判断
        QMessageBox::warning(nullptr, "警告", "无内容！", QMessageBox::Yes);
    } else {
        const auto    ch           = input_char.at(0);
        const auto    unicode_char = ch.unicode();
        const QString info         = QString(ch) + QString::asprintf("\t，Unicode编码=0x%X", unicode_char);
        ui->plainTextEdit->appendPlainText(info);

        // 使用QChar的接口函数判断字符的特性
        ui->checkBox_isDigit->setChecked(ch.isDigit());                   // 是否为数字0～9
        ui->checkBox_isLetter->setChecked(ch.isLetter());                 // 是否为字母
        ui->checkBox_isLetterOrNumber->setChecked(ch.isLetterOrNumber()); // 是否为字母或数字
        ui->checkBox_isUpper->setChecked(ch.isUpper());                   // 是否为大写字母
        ui->checkBox_isLower->setChecked(ch.isLower());                   // 是否为小写字母
        ui->checkBox_isMark->setChecked(ch.isMark());                     // 是否为记号
        ui->checkBox_isSpace->setChecked(ch.isSpace());                   // 是否为空白符
        ui->checkBox_isSymbol->setChecked(ch.isSymbol());                 // 是否为符号
        ui->checkBox_isPunct->setChecked(ch.isPunct());                   // 是否为标点符号
    }
}

void
Widget::on_pushButton_to_Latin1_clicked() const {
    QString test_str = "Dimple"; // 测试字符串
    ui->plainTextEdit->clear();  // 清空文本框
    ui->plainTextEdit->appendPlainText(test_str);
    constexpr QChar ch_P = QChar::fromLatin1('P'); // Latin1字符
    test_str[0]          = ch_P;
    ui->plainTextEdit->appendPlainText("\n" + test_str); // 替换
}

void
Widget::on_pushButton_utf16_conversion_clicked() const {
    QString test_str = "Hello，上海！";
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(test_str);        // 原本字符串
    test_str[6] = QChar(0x4e2d);                         // '中'
    test_str[7] = QChar(0x56fd);                         // '国'
    ui->plainTextEdit->appendPlainText("\n" + test_str); // 替换输出
}

void
Widget::on_pushButton_clear_clicked() const {
    ui->plainTextEdit->clear();
}

void
Widget::on_pushButton_qchar_judgement_and_replace_clicked() const {
    const QString str_qt = "Hello Qt"; // const char*类型初始化str
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(str_qt);
    ui->plainTextEdit->appendPlainText(QString("索引值为7的字符为：") + str_qt.at(7)); // 't'
    const QString str_chinese = "你好，世界";
    ui->plainTextEdit->appendPlainText(QString("\n") + str_chinese);
    ui->plainTextEdit->appendPlainText(QString("索引值为1的字符为：") + str_chinese.at(1)); // '\u597d' -> '好'

    const QString str_material = "河湖";                                       // 替换素材
    const QChar   str_He       = QChar::fromUcs2(str_material[0].unicode()); // 获取“河”的UTF-16编码，再构造一个QChar
    const auto    str_Hu       = QChar(str_material[1].unicode());
    QString       str_example  = "\n他们来自河南与河北";

    ui->plainTextEdit->appendPlainText(str_example);
    for (auto &i : str_example) {
        if (i == str_He) { // 逻辑比较
            i = str_Hu;
        }
    }
    ui->plainTextEdit->appendPlainText(QString("通过逻辑比较（比较UTF16编码），将‘河’替换为‘湖’：") + str_example);
}
