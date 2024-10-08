// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget) {
    ui->setupUi(this);
    /** 男孩 */
    boy = new TPerson("张三", this); /// this为窗口对象，这样二者加入到窗口的对象树
    /// 属性设置
    boy->setProperty("age", 20);
    boy->setProperty("score", 95);
    boy->setProperty("sex", "Boy");
    /** 动态属性
     * 动态属性针对类的实例定义
     */
    connect(boy, &TPerson::ageChanged, this, &Widget::do_ageChanged);

    /** 女孩 */
    girl = new TPerson("翠花", this);
    girl->setProperty("age", 21);
    girl->setProperty("score", 81);
    girl->setProperty("sex", "Girl");
    connect(girl, &TPerson::ageChanged, this, &Widget::do_ageChanged);

    /// 设置微调框
    ui->spinbox_boy->setProperty("isBoy", true); /// 动态属性isBoy
    ui->spinbox_girl->setProperty("isGirl", false);
    /// 连接（以两种方式表示）
    connect(
            ui->spinbox_boy,
            &QSpinBox::valueChanged,
            this,
            &Widget::do_spinChanged);
    connect(
            ui->spinbox_girl,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(do_spinChanged(int)));
}

Widget::~Widget() { delete ui; }

void
Widget::do_ageChanged(const int age) const {
    Q_UNUSED(age);
    const auto person      = qobject_cast<TPerson *>(sender()); /// 获取信号发射者
    const auto person_name = person->property("name").toString();
    const auto person_sex  = person->property("sex").toString();
    const int  person_age  = person->age();
    /// person_age             = person->property("age").toInt(); /// 通过属性获得
    const auto person_info = QString("name: %1,\t sex: %2,\t age: %3\n").
                             arg(person_name, person_sex).arg(
                                     person_age);
    ui->plaintext_edit->appendPlainText(person_info);
}

void
Widget::do_spinChanged(const int age) const {
    if (const auto spin_box = qobject_cast<QSpinBox *>(sender()); spin_box->
                                                                  property("isBoy").toBool()) {
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
    ui->plaintext_edit->appendPlainText(
            QString("-----------\nClass name: %1\n").arg(meta->className()));
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
                QString("name: %1,\t value: %2\n").arg(
                        class_info.name(),
                        class_info.value()));
    }
    ui->plaintext_edit->appendPlainText("-----------\n");

    /// 测试项
    TestContainer();
    TestIterator();
    TestQVariant();
    TestRandomGenerator();
}

void
Widget::print_properties(const QObject *obj) const {
    const auto meta = obj->metaObject();
    for (int i = meta->propertyOffset(); i < meta->propertyCount(); ++i) {
        const auto property_name = meta->property(i).name();
        /// 需含<QtCore/QMetaProperty>头文件
        const auto property_value  = obj->property(property_name).toString();
        const auto properties_info = QString("property type: %1,\t value: %2\n")
                .
                arg(
                        property_name,
                        property_value);
        ui->plaintext_edit->appendPlainText(properties_info);
    }
}

void
Widget::TestContainer() {
    QMultiMap<QString, int> num1, num2;
    num1.insert("rout", 100000);
    num1.insert("rout", 200000);   /// num1.size()=2
    num2.insert("rout", 300000);   /// num2.size()=1
    const auto num3 = num1 + num2; /// num3.size()=3

    const auto values = num3.values("rout");
    for (const auto value : values) {
        qDebug() << value << "\t"; /// 输出
    }
}

void
Widget::TestIterator() {
    /**
     * 1. 顺序容器
     */
    QList<QString> list_string;
    list_string << "A" << "B" << "C" << "D" << "E" << "F";
    for (QList<QString>::const_iterator iterator = list_string.constBegin();
         iterator != list_string.constEnd(); ++
         iterator) {
        /// 只读迭代器，逐项读出
        qDebug() << *iterator; /// Debug优先级更高，会在缓冲区中优先读出。
    }

    for (auto reverse_iterator = list_string.rbegin();
         reverse_iterator != list_string.rend(); ++reverse_iterator) {
        /// 反向修改项内容为小写
        *reverse_iterator = reverse_iterator->toLower(); /// *运算符返回数据项内容
    }

    /**
     * 2. 关联容器
     */
    QMultiMap<QString, int> num1, num2;
    num1.insert("rout", 100000);
    num1.insert("rout", 200000);                /// num1.size()=2
    num2.insert("rout", 300000);                /// num2.size()=1
    QMultiMap<QString, int> num3 = num1 + num2; /// num3.size()=3
    num3.insert("test", 1);

    for (QMultiMap<QString, int>::const_iterator iterator = num3.constBegin();
         iterator != num3.constEnd(); ++
         iterator) {
        /// 所有项的键和值输出
        qDebug() << iterator.key() << ":" << iterator.value();
    }

    /**
     * 3. foreach 遍历
     * @remark C++11引入基于范围的循环，Qt不建议继续使用foreach。
     */
    foreach(const QString& value, list_string) {
        /// value必须是后者容器内类型
        if (value == "c") { break; }
        qDebug() << value;
    }

    QHash<QString, QString> string_hash;
    string_hash.insert("Hello", "World");
    string_hash.insert("Welcome", "China");

    foreach(const QString& str, string_hash.keys()) {
        /// 无需调用values函数
        qDebug() << str << ":" << string_hash.value(str);
    }
    foreach(const auto& str, num3.uniqueKeys()) {
        /*获取唯一键*/
        foreach(const auto& num, num3.values(str)) {
            /*双重遍历*/
            qDebug() << str << ":" << num;
        }
    }
}

void
Widget::TestQVariant() const {
    /** 1. 普通类型存储 */
    QVariant      var(123);                   /// 默认初值
    const QString str     = var.toString();   /// str="123"，通过toT函数转换具体数据类型
    const int     var_int = var.value<int>(); /// val_int=123，value()返回某种类型数据
    qDebug() << "str: " << str << ", var_int:" << var_int;

    /** 2. 字符串列表存储 */
    QStringList string_list;
    string_list << "Hello, " << "Welcome " << "China";
    var.setValue(string_list);      /// 赋予一个字符串列表
    qDebug() << var.toStringList(); /// 转换为字符串列表输出（注意：不能直接输出字符串）

    /** 3. 模块值存储 */
    var                  = ui->pushbutton_display_metainfo->font(); /// 赋予按钮字体
    const auto font_copy = var.value<QFont>();                      /// 转换类型
    qDebug() << font_copy.toString();
}

void
Widget::TestRandomGenerator() {
    /// 生成随机数，比较随机数因随机数种子而发生的变化
    const auto const_seed = QDateTime::currentMSecsSinceEpoch() - 1;
    const auto rand1      = new QRandomGenerator64(const_seed);
    const auto rand2      = new QRandomGenerator64(const_seed);
    const auto rand3      = new QRandomGenerator64(QDateTime::currentMSecsSinceEpoch());
    for (int i = 0; i < 5; ++i) {
        qDebug("Random1 is %llu,\nRandom2 is %llu,\nRandom3 is %llu.\n",
               rand1->generate64(),
               rand2->generate64(),
               rand3->generate64());
    }

    /// 也可以使用securelySeeded()单独生成随机数发生器
    qDebug("Random4 is %llu.\n", QRandomGenerator::securelySeeded().generate64());

    /// 如果短时间使用，或生成的随机数数据量比较小，可以使用静态函数global()表示全局的随机数发生器
    qDebug("Random5 is %llu.\n", QRandomGenerator::global()->generate64());

    /// 一组随机数
    /// @{
    /// 列表形式
    QList<quint64> random_numbers;
    random_numbers.resize(12);                                                             /// 设置列表长度
    QRandomGenerator64::system()->fillRange(random_numbers.data(), random_numbers.size()); /// 填充

    /// 数组形式
    quint64 array[12];
    QRandomGenerator64::system()->fillRange(array);
    /// @}

    qDebug("list is:\n");
    for (const auto &number : random_numbers) {
        qDebug() << number << "\t";
    }
    qDebug("array is:\n");
    for (const auto &number : array) {
        qDebug() << number << "\t";
    }

    /// 生成指定区间随机数，区间范围[a,b)
    /// 生成60～100间随机数
    qDebug("\nscores is:");
    for (int i = 0; i < 10; ++i) {
        qDebug("%u", QRandomGenerator64::system()->bounded(60, 101));
    }

    delete rand1;
    delete rand2;
    delete rand3;
}
