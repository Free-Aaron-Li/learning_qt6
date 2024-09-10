#include "widget.h"

#include <QPushButton>

#include "./ui_widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::Widget) {
    ui->setupUi(this);
    setWindowTitle("运行时类型信息");

    /// 1. 函数 QMetaObject::className()
    const auto         push_button        = new QPushButton();
    const QMetaObject* meta_object        = push_button->metaObject(); /// 获取对象的元对象指针
    const auto         string_push_button = QString(meta_object->className()); /// 获取该元对象类名

    /// 2. 函数 QObject::inherits()
    const bool result1 = push_button->inherits("QPushButton"); /// 判断一个对象是否继承自某个类的实例
    const bool result2 = push_button->inherits("QObject"); /// 如果多重继承，只要符合其中一个父类，即返回true
    const bool result3 = push_button->inherits("QWidget");
    const bool result4 = push_button->inherits("QCheckBox");

    /// 3. 函数 QMetaObject::superClass()
    const auto string_push_button_parent = QString(meta_object->superClass()->className()); /// 返回元对象所描述类的父类元对象

    /// 4. 函数 qobject_cast()
    QObject*   object_button    = new QPushButton(); /// 创建QPushButton，但是使用QObject指针
    const auto button_name      = QString(object_button->metaObject()->className());
    const auto real_button      = qobject_cast<QPushButton*>(object_button); /// 对于QOject及其子类的对象，实现动态类型转换
    const auto real_button_name = QString(real_button->metaObject()->className());

    /// QCheckBox* false_button = qobject_cast<QPushButton*>(object_button);
    /// 转换失败，对象指针类型不同，因为QCheckBox不是QPushButton的父类。
    /// 使用qobject_cast()的好处是不需要C++编译器开启RTTI的支持。

    // 显示
    QString display = "Welcome!\n";
    display += "class name is: " + string_push_button + ".\n" + "QPushButton is his parent class? " + IsTure(result1) +
        ".\nQObject is his parent class? " + IsTure(result2) + ".\nQWidget is his parent class? " + IsTure(result3) +
        ".\nQCheckBox is his parent class? " + IsTure(result4) + ".\nSo, what is his previous parent class? " +
        string_push_button_parent + ".\nHere has a QObject class, his name is: " + button_name +
        ", oh! we need conversion his type, then his real class type is: " + real_button_name + ".\n";
    ui->plain_text_edit->setPlainText(display);
}

Widget::~Widget() { delete ui; }

QString
Widget::IsTure(const bool value) {
    if (value)
        return "true";
    else
        return "false";
}