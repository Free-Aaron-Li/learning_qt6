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

 private:
    Ui::Widget *ui;
    // 显示逻辑值
    void        ShowBoolInfo(const QString &str, bool check_value) const;

 private slots:
    // 清空文本框
    void on_pushButton_clear_clicked() const;
    // 测试front()和back()函数
    void on_pushButton_front_and_back_clicked() const;
    // 测试sliced()函数
    void on_pushButton_sliced_clicked() const;
    // 测试first()和last()函数
    void on_pushButton_first_and_last_clicked() const;
    // 测试section()函数
    void on_pushButton_section_clicked() const;
    // 测试isNull()和isEmpty()函数
    void on_pushButton_isNull_and_isEmpty_clicked() const;
    // 测试resize()函数
    void on_pushButton_resize_clicked() const;
    // 测试size()和length()函数
    void on_pushButton_size_and_length_clicked() const;
    // 测试fill()函数
    void on_pushButton_fill_clicked() const;
    // 测试indexOf()和lastIndexOf()函数
    void on_pushButton_indexOf_and_lastIndexOf_clicked() const;
    // 测试contains()函数
    void on_pushButton_contains_clicked() const;
    // 测试endsWith()和startsWith()函数
    void on_pushButton_endsWith_and_startsWith_clicked() const;
    // 测试count()函数
    void on_pushButton_count_clicked() const;
    // 测试trimmed()和simplified()函数
    void on_pushButton_trimmed_and_simplified_clicked() const;
    // 测试insert()和remove()函数
    void on_pushButton_insert_clicked() const;
    // 测试replace()函数
    void on_pushButton_remove_clicked() const;
    // 测试replace()函数
    void on_pushButton_replace_clicked() const;
};
#endif  // WIDGET_H
