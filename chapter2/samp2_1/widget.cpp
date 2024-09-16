// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::Widget) {
    ui->setupUi(this);
    ui->labDemo->setText("欢迎使用Qt6");
    ui->btnClose->setText("关闭");
}

Widget::~Widget() { delete ui; }