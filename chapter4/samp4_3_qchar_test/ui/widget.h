// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#ifndef WIDGET_H
#define WIDGET_H

#include <QString>
#include <QMessageBox>

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
    /**
     * @brief 获取字符的Unicode编码
     */
    void on_pushButton_unicode_conversion_clicked() const;
    /**
     * @brief 判断QChar字符的特性
     */
    void on_pushButton_char_judgement_clicked() const;

    /**
     * @brief 将字符转换为Latin1编码
     */
    void on_pushButton_to_Latin1_clicked() const;

    /**
     * @brief QChar的比较和替换
     */
    void on_pushButton_qchar_judgement_and_replace_clicked() const;

    /**
     * 与UTF-16的转换
     */
    void on_pushButton_utf16_conversion_clicked() const;

    /**
     * 清空文本框
     */
    void on_pushButton_clear_clicked() const;

private:
    Ui::Widget *ui;
};
#endif  // WIDGET_H
