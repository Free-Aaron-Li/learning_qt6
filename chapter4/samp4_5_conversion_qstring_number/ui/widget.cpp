// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#include "widget.h"

#include <QMessageBox>

#include "./ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget) { ui->setupUi(this); }

Widget::~Widget() { delete ui; }

void
Widget::on_pushButton_calculate_total_price_clicked() const {
    // text()和setText()函数用于QLineEdit控件的读取和写入
    bool ok = true;
    const auto amount = ui->lineEdit_amount->text().toInt(&ok); // 当输入浮点数，返回值为0
    if (!ok) {
        // 获取当前活跃窗口作为父窗口，注意：不要使用nullptr，因为消息可以随机显示
        QMessageBox::warning(QApplication::activeWindow(), "警告", "请输入正确的数量");
        // 将焦点放回输入框
        ui->lineEdit_amount->setFocus();
        // 当用户输入无效数据时不建议立即重新执行计算，而是提示用户更正输入并重新按下控件
        return;
    } else {
        const auto unit_price = ui->lineEdit_unit_price->text().toFloat();
        const float total_price = unit_price * static_cast<float>(amount);
        QString total_price_str;
        total_price_str = total_price_str.setNum(total_price, 'f', 2); // 保留两位小数
        ui->lineEdit_total_price->setText(total_price_str);
    }
}

void
Widget::on_pushButton_dec_conversion_clicked() const {
    bool ok = true;
    const auto dec_value = ui->lineEdit_dec->text().toLong(&ok, 10);
    if (!ok) {
        QMessageBox::warning(QApplication::activeWindow(), "警告", "请输入正确的十进制数字");
        ui->lineEdit_amount->setFocus();
        return;
    } else {
        ui->lineEdit_bin->setText(QString::number(dec_value, 2));
        ui->lineEdit_hex->setText(QString::number(dec_value, 16)); // 显示为十六进制
    }
}

void
Widget::on_pushButton_bin_conversion_clicked() const {
    bool ok = true;
    const auto bin_value = ui->lineEdit_bin->text().toLong(&ok, 2); // 读取二进制
    if (!ok) {
        QMessageBox::warning(QApplication::activeWindow(), "警告", "请输入正确的二进制数字");
        ui->lineEdit_amount->setFocus();
        return;
    } else {
        ui->lineEdit_dec->setText(QString::number(bin_value, 10)); // 显示为十进制
        ui->lineEdit_hex->setText(QString::number(bin_value, 16));
    }
}

void
Widget::on_pushButton_hex_conversion_clicked() const {
    bool ok = true;
    const auto hex_value = ui->lineEdit_hex->text().toLong(&ok, 16);
    if (!ok) {
        QMessageBox::warning(QApplication::activeWindow(), "警告", "请输入正确的十六进制数字");
        ui->lineEdit_amount->setFocus();
        return;
    } else {
        ui->lineEdit_dec->setText(QString::number(hex_value, 10)); // 显示为十进制
        ui->lineEdit_bin->setText(QString::number(hex_value, 2));
    }
}
