#include "dialog.h"

#include <QHBoxLayout>
#include <QPushButton>

Dialog::Dialog(QWidget* parent)
    : QDialog(parent) {
    InitUI();
    InitSignalSlots();
    setWindowTitle("手工创建UI");
}

Dialog::~Dialog() = default;

void
Dialog::InitUI() {
    /// 1. 创建三个复选框，并水平布局
    check_box_under_    = new QCheckBox("Underline");
    check_box_italic_   = new QCheckBox("Italic");
    check_box_bold_     = new QCheckBox("bold");
    auto* h_box_layout1 = new QHBoxLayout();
    h_box_layout1->addWidget(check_box_under_);
    h_box_layout1->addWidget(check_box_bold_);
    h_box_layout1->addWidget(check_box_italic_);

    /// 2. 创建三个单选框，并水平布局
    radio_button_black_ = new QRadioButton("Black");
    radio_button_black_->setCheckable(true);
    radio_button_blue_  = new QRadioButton("Blue");
    radio_button_red_   = new QRadioButton("Red");
    auto* h_box_layout2 = new QHBoxLayout();
    h_box_layout2->addWidget(radio_button_black_);
    h_box_layout2->addWidget(radio_button_red_);
    h_box_layout2->addWidget(radio_button_blue_);

    /// 3. 创建三个逻辑按钮，并水平布局
    push_button_confirm_ = new QPushButton("确定");
    push_button_cancel_  = new QPushButton("取消");
    push_button_quit_    = new QPushButton("退出");
    auto* h_box_layout3  = new QHBoxLayout();
    h_box_layout3->addWidget(push_button_confirm_);
    h_box_layout3->addWidget(push_button_cancel_);
    h_box_layout3->addWidget(push_button_quit_);

    /// 4. 创建文本框，并设置初始化字体
    plain_text_edit_ = new QPlainTextEdit;
    plain_text_edit_->setPlainText("Hello World!\n手工创建界面。");
    QFont font = plain_text_edit_->font(); /// 获取字体
    font.setPixelSize(20); /// 修改字体大小
    plain_text_edit_->setFont(font); /// 设置字体

    /// 5. 创建垂直布局，并设置为主布局
    auto* v_box_layout = new QVBoxLayout(this);
    v_box_layout->addLayout(h_box_layout1); /// 字体样式
    v_box_layout->addLayout(h_box_layout2); /// 字体颜色
    v_box_layout->addWidget(plain_text_edit_); /// 文本框
    v_box_layout->addLayout(h_box_layout3); /// 逻辑按钮组合
    setLayout(v_box_layout); /// 设置为窗口的主布局
}

void
Dialog::InitSignalSlots() const {
    /// 字体设置复选框
    /// 采用这种方式无需出现函数参数，当出现同名的信号，Qt会自动选择
    connect(check_box_under_, &QCheckBox::clicked, this, &Dialog::do_check_box_under_);
    connect(check_box_italic_, &QCheckBox::clicked, this, &Dialog::do_check_box_italic_);
    connect(check_box_bold_, &QCheckBox::clicked, this, &Dialog::do_check_box_bold_);

    /// 颜色设置单选框
    connect(radio_button_black_, &QCheckBox::clicked, this, &Dialog::do_SetFontColor);
    connect(radio_button_red_, &QCheckBox::clicked, this, &Dialog::do_SetFontColor);
    connect(radio_button_blue_, &QCheckBox::clicked, this, &Dialog::do_SetFontColor);

    /// 逻辑按钮组合
    connect(push_button_confirm_, &QCheckBox::clicked, this, &Dialog::accept);
    connect(push_button_cancel_, &QCheckBox::clicked, this, &Dialog::accept);
    connect(push_button_quit_, &QCheckBox::clicked, this, &Dialog::accept);
}


void
Dialog::do_check_box_under_(const bool checked) const {
    QFont font = plain_text_edit_->font();
    font.setUnderline(checked);
    plain_text_edit_->setFont(font);
}

void
Dialog::do_check_box_italic_(const bool checked) const {
    QFont font = plain_text_edit_->font();
    font.setItalic(checked);
    plain_text_edit_->setFont(font);
}

void
Dialog::do_check_box_bold_(const bool checked) const {
    QFont font = plain_text_edit_->font();
    font.setBold(checked);
    plain_text_edit_->setFont(font);
}

void
Dialog::do_SetFontColor() const {
    QPalette palette = plain_text_edit_->palette();
    if (radio_button_black_->isChecked())
        palette.setColor(QPalette::Text, Qt::black);
    else if (radio_button_red_->isChecked())
        palette.setColor(QPalette::Text, Qt::red);
    else if (radio_button_blue_->isChecked())
        palette.setColor(QPalette::Text, Qt::blue);

    plain_text_edit_->setPalette(palette);
}