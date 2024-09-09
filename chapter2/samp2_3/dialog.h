#ifndef DIALOG_H
#define DIALOG_H

#include <QCheckBox>
#include <QDialog>
#include <QPlainTextEdit>
#include <QRadioButton>

QT_BEGIN_NAMESPACE

namespace Ui
{
class Dialog;
}

QT_END_NAMESPACE

class Dialog final : public QDialog {
    Q_OBJECT /// 确保该类可以使用元对象系统的特性

public:
    explicit Dialog(QWidget* parent = nullptr);

    ~Dialog() override;

private:
    Ui::Dialog* ui{};
    /// 文本格式复选框
    QCheckBox* check_box_under_{};
    QCheckBox* check_box_italic_{};
    QCheckBox* check_box_bold_{};
    /// 颜色选择按钮
    QRadioButton* radio_button_black_{};
    QRadioButton* radio_button_red_{};
    QRadioButton* radio_button_blue_{};

    /// 逻辑按钮
    QPushButton* push_button_confirm_{}; /// 确定
    QPushButton* push_button_cancel_{}; /// 取消
    QPushButton* push_button_quit_{}; /// 退出

    /// 文本框
    QPlainTextEdit* plain_text_edit_{};

    void InitUI(); /// 初始化UI
    void InitSignalSlots() const; /// 初始化信号与槽的连接

private slots:
    void do_check_box_under_(bool checked) const; /// 下划线复选框
    void do_check_box_italic_(bool checked) const; /// 斜体复选框
    void do_check_box_bold_(bool checked) const; /// 加粗复选框
    void do_SetFontColor() const; /// 设置文字颜色

};
#endif  // DIALOG_H