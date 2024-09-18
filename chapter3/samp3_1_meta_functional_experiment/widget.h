// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore/QMetaProperty>
#include <QRandomGenerator64>
#include <QDateTime>
#include "tperson.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class Widget;
}

QT_END_NAMESPACE

class Widget final : public QWidget {
  Q_OBJECT

public:
  explicit Widget(QWidget* parent = nullptr);

  ~Widget() override;

private:
  TPerson* boy;
  TPerson* girl;

private:
  Ui::Widget* ui;

private slots:
  /// 设置槽函数
  void do_ageChanged(int age) const;

  void do_spinChanged(int age) const;

  void on_pushbutton_boy_grow_up_clicked() const;

  void on_pushbutton_girl_grow_up_clicked() const;

  void on_pushbutton_clean_clicked() const;

  void on_pushbutton_display_metainfo_clicked() const;

  void print_properties(const QObject* obj) const;

  static inline void TestContainer(); /// 关联容器

  static inline void TestIterator(); /// 迭代器

  void TestQVariant() const; /// QVariant类

  static inline void TestRandomGenerator();
};

#endif