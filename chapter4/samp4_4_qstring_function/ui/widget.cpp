// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget) { ui->setupUi(this); }

Widget::~Widget() { delete ui; }

/**
 * @brief 显示逻辑值
 * @param str 输入字符串
 * @param check_value 按钮clicked()信号逻辑值
 */
void
Widget::ShowBoolInfo(const QString &str, const bool check_value) const {
    if (check_value) {
        ui->plainTextEdit->appendPlainText(str + " = true");
    } else {
        ui->plainTextEdit->appendPlainText(str + " = false");
    }
}

void
Widget::on_pushButton_clear_clicked() const {
    ui->plainTextEdit->clear();
}

void
Widget::on_pushButton_front_and_back_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==front()和back()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "返回字符串第一个（最后一个）字符\n"
            "---\n");
    ui->plainTextEdit->appendPlainText("front()：\t" + QString(ui->comboBox_str1->currentText().front()));
    ui->plainTextEdit->appendPlainText("back()：\t" + QString(ui->comboBox_str1->currentText().back()));
}

void
Widget::on_pushButton_sliced_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==sliced()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "根据位置pos返回截取字符串（包含pos）【Qt6引入，代替mid()函数】\n"
            "---\n");
    const auto str1 = ui->comboBox_str1->currentText();
    const auto str2 = ui->comboBox_str2->currentText();
    ui->plainTextEdit->appendPlainText("str1 = \t" + str1);
    ui->plainTextEdit->appendPlainText("str2 = \t" + str2);

    const auto index_of_str1      = str1.indexOf(str2);
    const auto last_index_of_str1 = str1.lastIndexOf(str2);
    ui->plainTextEdit->appendPlainText("sliced()截取从第一个“/”开始的数据：" + str1.sliced(index_of_str1));
    ui->plainTextEdit->appendPlainText(
            "sliced()截取从第一个“/”开始到最后一个“/”的数据：" + str1.sliced(index_of_str1, last_index_of_str1));
}

void
Widget::on_pushButton_first_and_last_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==first()，last()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "从字符串中提取最前面（最后面）n个字符（包含pos）【Qt6引入，代替left()，right()函数】\n"
            "---\n");
    const auto str1 = ui->comboBox_str1->currentText();
    const auto str2 = ui->comboBox_str2->currentText();
    ui->plainTextEdit->appendPlainText("str1 = \t" + str1);
    ui->plainTextEdit->appendPlainText("str2 = \t" + str2);

    const auto last_index_of_str1 = str1.lastIndexOf(str2);
    ui->plainTextEdit->appendPlainText(
            "first()函数截取至str2最后出现位置（包含/）：" + str1.first(last_index_of_str1 - 1));
    ui->plainTextEdit->appendPlainText(
            "last()函数截取至str2最后出现位置（不包含/）：" + str1.last(str1.size() - last_index_of_str1 - 1));
}

void
Widget::on_pushButton_section_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==section()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "以sep作为分隔符，从start段到end段提取字符串\n"
            "---\n");
    const auto str1 = ui->comboBox_str1->currentText();
    const auto str2 = ui->comboBox_str2->currentText();
    ui->plainTextEdit->appendPlainText("str1 = \t" + str1);
    ui->plainTextEdit->appendPlainText("str2 = \t" + str2);
    ui->plainTextEdit->appendPlainText("section()函数提取全部信息（即：str2,0,-1[默认]）：" + str1.section(str2, 0));

    const auto count = str1.count("/");
    ui->plainTextEdit->appendPlainText(
            "section()函数提取“/”中数据（即：str2,1,count-1）【不包含/】：" + str1.section(str2, 1, count - 1));
}

void
Widget::on_pushButton_isNull_and_isEmpty_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==isNull()，isEmpty()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "判断字符串是否为空【💡：空字符串包含“\\0”，isNull认为是false】\n"
            "---\n");
    const QString str1;
    QString       str2 = "";
    ui->plainTextEdit->appendPlainText(
            "QString str1, str2="
            "");
    ShowBoolInfo("str1.isNull()", str1.isNull());
    ShowBoolInfo("str1.isEmpty()", str1.isEmpty());
    ShowBoolInfo("\nstr2.isNull()", str2.isNull());
    ShowBoolInfo("str2.isEmpty()", str2.isEmpty());
    str2.clear();
    ui->plainTextEdit->appendPlainText("\nstr2.clear()后");
    ShowBoolInfo("str2.isNull()", str2.isNull());
    ShowBoolInfo("str2.isEmpty()", str2.isEmpty());
}

void
Widget::on_pushButton_resize_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==resize()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "依照当前字符串长度进行扩充（截断）字符串\n"
            "---\n");
    auto       str1      = ui->comboBox_str1->currentText();
    const auto str1_size = str1.size();
    ui->plainTextEdit->appendPlainText("str1 size: \t" + str1_size);
    str1.resize(str1_size + 10);
    ui->plainTextEdit->appendPlainText("str1 size+10: \t" + str1);
    str1.resize(str1_size - 10);
    ui->plainTextEdit->appendPlainText("str1 size-10: \t" + str1);
    str1.resize(str1_size + 10, '*');
    ui->plainTextEdit->appendPlainText("str1 size+10(fill \"*\"): \t" + str1);
}

void
Widget::on_pushButton_size_and_length_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==size()，length()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "返回字符串长度\n"
            "---\n");
    const auto str1 = ui->comboBox_str1->currentText();
    ui->plainTextEdit->appendPlainText("str1 size(): \t" + QString::number(str1.size()));
    ui->plainTextEdit->appendPlainText("str1 length(): \t" + QString::number(str1.length()));
}

void
Widget::on_pushButton_fill_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==fill()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "将字符串中的每个字符都用一个新字符替换，且可以改变字符串长度\n"
            "---\n");
    auto str1 = ui->comboBox_str1->currentText();
    ui->plainTextEdit->appendPlainText("str1: \t" + str1);
    ui->plainTextEdit->appendPlainText("将全部字符替换为x：\t" + str1.fill('x'));
    ui->plainTextEdit->appendPlainText("将字符串替换为“哈哈”：\t" + str1.fill(QChar(0x54c8), 2));
}

void
Widget::on_pushButton_indexOf_and_lastIndexOf_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==indexOf()，lastIndexOf()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "从字符串中查找子字符串，返回子字符串在字符串中的位置（从0开始）\n"
            "---\n");
    const auto str1 = ui->comboBox_str1->currentText();
    const auto str2 = ui->comboBox_str2->currentText();
    ui->plainTextEdit->appendPlainText("str1 = \t" + str1);
    ui->plainTextEdit->appendPlainText("str2第一次出现位置为：" + QString::number(str1.indexOf(str2)));
    ui->plainTextEdit->appendPlainText("str2最后一次出现位置为：" + QString::number(str1.lastIndexOf(str2)));
}

void
Widget::on_pushButton_contains_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==contains()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "判断字符串是否包含子字符串\n"
            "---\n");
    const auto str1 = ui->comboBox_str1->currentText();
    ShowBoolInfo("str1是否包含.Cpp结尾文件？【不区分大小写（默认）】\t", str1.contains(".Cpp", Qt::CaseInsensitive));
    ShowBoolInfo("str1是否包含.cpp结尾文件？【区分大小写】\t", str1.contains(".cpp", Qt::CaseSensitive));
}

void
Widget::on_pushButton_endsWith_and_startsWith_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==endsWith()，startsWith()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "判断字符串是否以某子字符串结尾或开头【默认不区分大小写】\n"
            "---\n");
    const auto str1 = ui->comboBox_str1->currentText();
    ShowBoolInfo("str1是否以“.cpp”结尾？\t", str1.endsWith(".cpp"));
    ShowBoolInfo("str1是否以“~”开头？\t", str1.startsWith("~"));
}

void
Widget::on_pushButton_count_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==count()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "统计字符串中某子字符串出现的次数【也可以统计字符串总字数，已弃用】\n"
            "---\n");
    const auto str1 = ui->comboBox_str1->currentText();
    ui->plainTextEdit->appendPlainText("str1中“~”出现的次数为：" + QString::number(str1.count("~")));
    //ui->plainTextEdit->appendPlainText("str1中字数为：" + QString::number(str1.count()));
}

void
Widget::on_pushButton_trimmed_and_simplified_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==trimmed()，simplified()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "去除字符串首尾空格，trimmed()函数只去除空格，simplified()函数去除空格、制表符、换行符等\n"
            "---\n");
    const QString str1 = "ARE YOU    OK\t\t?\n";
    ui->plainTextEdit->appendPlainText("str1: \t" + str1);
    ui->plainTextEdit->appendPlainText("str1.trimmed(): " + str1.trimmed());
    ui->plainTextEdit->appendPlainText("str1.simplified(): " + str1.simplified());
}

void
Widget::on_pushButton_insert_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==insert()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "在字符串中插入子字符串，返回新字符串\n"
            "---\n");
    QString str1 = "It is great.";
    ui->plainTextEdit->appendPlainText("str1: \t" + str1);
    const auto last_index_of_str1 = str1.lastIndexOf(" ");
    ui->plainTextEdit->appendPlainText("在最后一个空格位置插入语句：" + str1.insert(last_index_of_str1, "n't"));
}

void
Widget::on_pushButton_remove_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==remove()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "从pos位置开始移除n个字符，也可以移除指定字符\n"
            "---\n");
    QString str1 = "你的，我的，他的";
    ui->plainTextEdit->appendPlainText("str1: \t" + str1);
    ui->plainTextEdit->appendPlainText("删除所有“，”：" + str1.remove(QChar(str1[2].unicode())));
    // 字符以UTF-16表示，所以一个汉字也算一个字符，而非两个字符
    ui->plainTextEdit->appendPlainText("删除“你的”后续两个字符：" + str1.remove(str1.indexOf(QChar(str1[2].unicode())), 2));
}

void
Widget::on_pushButton_replace_clicked() const {
    ui->plainTextEdit->appendPlainText("\n==replace()函数测试==\n");
    ui->plainTextEdit->appendPlainText(
            "---\n"
            "将字符串中的子字符串替换为另一个子字符串，返回新字符串\n"
            "---\n");
    QString str1 = "It is great.";
    ui->plainTextEdit->appendPlainText("str1: \t" + str1);
    ui->plainTextEdit->appendPlainText("将“great”替换为“good”：" + str1.replace("great", "good"));
}
