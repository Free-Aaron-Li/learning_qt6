#include "widget.h"

#include <iostream>

#include "./ui_widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::Widget) {
    ui->setupUi(this);
    /// 男孩
    boy = new TPerson("张三", this); /// this为窗口对象，这样二者加入到窗口的对象树
    /// 属性设置
    boy->setProperty("age", 20);
    boy->setProperty("score", 95);
    boy->setProperty("sex", "Boy"); /// 动态属性
                                               /// 动态属性针对类的实例定义
    connect(boy, &TPerson::ageChanged, this, &Widget::do_ageChanged);

    /// 女孩
    girl = new TPerson("翠花", this);
    girl->setProperty("age", 21);
    girl->setProperty("score", 81);
    girl->setProperty("sex", "Girl");
    connect(girl, &TPerson::ageChanged, this, &Widget::do_ageChanged);

    /// 设置微调框
    ui->spinbox_boy->setProperty("isBoy", true); /// 动态属性isBoy
    ui->spinbox_girl->setProperty("isGirl", false);
    /// 连接（以两种方式表示）
    connect(ui->spinbox_boy, &QSpinBox::valueChanged, this, &Widget::do_spinChanged);
    connect(ui->spinbox_girl, SIGNAL(valueChanged(int)), this, SLOT(do_spinChanged(int)));
}

Widget::~Widget() { delete ui; }

void
Widget::do_ageChanged(const int age) const {
    Q_UNUSED(age);
    const auto person      = qobject_cast<TPerson*>(sender()); /// 获取信号发射者
    const auto person_name = person->property("name").toString();
    const auto person_sex  = person->property("sex").toString();
    const int  person_age  = person->age();
    /// person_age             = person->property("age").toInt(); /// 通过属性获得
    const auto person_info = QString("name: %1,\t sex: %2,\t age: %3\n").arg(person_name).arg(person_sex).arg(
        person_age);
    ui->plaintext_edit->appendPlainText(person_info);
}

void
Widget::do_spinChanged(const int age) const {
    if (const auto spin_box = qobject_cast<QSpinBox*>(sender()); spin_box->property("isBoy").toBool()) {
        /// 根据isBoy判断，避免代码冗余
        boy->setAge(age);
    } else { girl->setAge(age); }
}

void
Widget::on_pushbutton_boy_grow_up_clicked() const { boy->IncreaseAge(); }

void
Widget::on_pushbutton_girl_grow_up_clicked() const { girl->IncreaseAge(); }

void
Widget::on_pushbutton_clean_clicked() const { ui->plaintext_edit->clear(); }

void
Widget::on_pushbutton_display_metainfo_clicked() const {
    const auto obj  = boy;
    const auto meta = obj->metaObject();
    ui->plaintext_edit->clear();
    ui->plaintext_edit->appendPlainText(QString("-----------\nClass name: %1\n").arg(meta->className()));
    /// 打印属性信息
    ui->plaintext_edit->appendPlainText("-----------\nProperties:\n");
    print_properties(boy);
    ui->plaintext_edit->appendPlainText("-----------\n");
    print_properties(girl);

    /// 打印类信息
    ui->plaintext_edit->appendPlainText("-----------\nClassInfo:\n");
    for (int i = meta->classInfoOffset(); i < meta->classInfoCount(); ++i) {
        auto class_info = meta->classInfo(i);
        ui->plaintext_edit->appendPlainText(
            QString("name: %1,\t value: %2\n").arg(class_info.name(), class_info.value()));
    }
    ui->plaintext_edit->appendPlainText("-----------\n");
    test();
}

void
Widget::print_properties(const QObject* obj) const {
    const auto meta = obj->metaObject();
    for (int i = meta->propertyOffset(); i < meta->propertyCount(); ++i) {
        const auto property_name   = meta->property(i).name(); /// 需含<QtCore/QMetaProperty>头文件
        const auto property_value  = obj->property(property_name).toString();
        const auto properties_info = QString("property type: %1,\t value: %2\n").arg(
            property_name,
            property_value);
        ui->plaintext_edit->appendPlainText(properties_info);
    }
}

void
Widget::test() {
    QMultiMap<QString, int> num1, num2;
    num1.insert("rout", 100000);
    num1.insert("rout", 200000); /// num1.size()=2
    num2.insert("rout", 300000); /// num2.size()=1
    const QMultiMap<QString, int> num3 = num1 + num2; /// num3.size()=3

    const auto values = num1.values("rout");
    for (const auto value : values) {
        std::cout << value << "\t"; /// 输出
    }
}