#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE

namespace Ui
{
class Dialog;
}

QT_END_NAMESPACE

class Dialog : public QDialog {
    Q_OBJECT

public:
    Dialog(QWidget* parent = nullptr);

    ~Dialog();

private slots:
    void on_cb_italic_clicked(bool checked) const;

    void on_cb_bold_clicked(bool checked) const;

    void on_cb_under_clicked(bool checked) const;

    void on_pbtn_clear_clicked() const;

    void do_set_font_color() const;

private:
    Ui::Dialog* ui;
};
#endif  // DIALOG_H
