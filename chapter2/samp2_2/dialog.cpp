#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget* parent)
    : QDialog(parent),
      ui(new Ui::Dialog) {
    ui->setupUi(this);
    /// 由于do_set_font_color槽函数是自定义的，所以需要手动进行click()信号关联
    connect(ui->rbtn_black, &QRadioButton::clicked, this, &Dialog::do_set_font_color);
    connect(ui->rbtn_red, &QRadioButton::clicked, this, &Dialog::do_set_font_color);
    connect(ui->rbtn_blue, &QRadioButton::clicked, this, &Dialog::do_set_font_color);
}

Dialog::~Dialog() { delete ui; }

/**
 * 纯文本下划线控制。
 */
void
Dialog::on_cb_under_clicked(const bool checked) const {
    QFont font = ui->pt_edit_display->font(); /// 获取纯文本字体
    font.setUnderline(checked); /// 根据是否点击确定是否添加下划线
    ui->pt_edit_display->setFont(font); /// 重置纯文本字体
}

/**
 * 纯文本斜体控制。
 */
void
Dialog::on_cb_italic_clicked(const bool checked) const {
    QFont font = ui->pt_edit_display->font(); /// 获取纯文本字体
    font.setItalic(checked); /// 根据是否点击确定是否添加下划线
    ui->pt_edit_display->setFont(font); /// 重置纯文本字体
}

/**
 * 纯文本加粗控制。
 */
void
Dialog::on_cb_bold_clicked(const bool checked) const {
    QFont font = ui->pt_edit_display->font(); /// 获取纯文本字体
    font.setBold(checked); /// 根据是否点击确定是否添加下划线
    ui->pt_edit_display->setFont(font); /// 重置纯文本字体
}

/**
* 清空纯文本
*/
void
Dialog::on_pbtn_clear_clicked() const {
    ui->pt_edit_display->clear(); /// 清空文本
}

/**
* 设置文字颜色的自定义槽函数，以do_作为自定义槽函数。
*/
void
Dialog::do_set_font_color() const {
    QPalette palette = ui->pt_edit_display->palette();
    if (ui->rbtn_black->isChecked())
        palette.setColor(QPalette::Text, Qt::black);
    else if (ui->rbtn_red->isChecked())
        palette.setColor(QPalette::Text, Qt::red);
    else if (ui->rbtn_blue->isChecked())
        palette.setColor(QPalette::Text, Qt::blue);

    ui->pt_edit_display->setPalette(palette);
}