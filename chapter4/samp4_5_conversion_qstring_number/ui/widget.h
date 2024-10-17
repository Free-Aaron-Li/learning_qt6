// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE

namespace Ui {
    class Widget;
}

QT_END_NAMESPACE

class Widget final : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private slots:
    // 计算总价
    void on_pushButton_calculate_total_price_clicked() const;
    // 十进制转换为其他进制
    void on_pushButton_dec_conversion_clicked() const;
    // 二进制转换为其他进制
    void on_pushButton_bin_conversion_clicked() const;
    // 十六进制转换为其他进制
    void on_pushButton_hex_conversion_clicked() const;

private:
    Ui::Widget *ui;
};
#endif  // WIDGET_H
