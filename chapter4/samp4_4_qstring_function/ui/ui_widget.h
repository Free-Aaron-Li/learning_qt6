/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame_buttons;
    QGroupBox *groupBox_storage_related;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_isNull_and_isEmpty;
    QPushButton *pushButton_resize;
    QPushButton *pushButton_size_and_length;
    QPushButton *pushButton_fill;
    QGroupBox *groupBox_string_interception;
    QGridLayout *gridLayout;
    QPushButton *pushButton_front_and_back;
    QPushButton *pushButton_sliced;
    QPushButton *pushButton_first_and_last;
    QPushButton *pushButton_section;
    QGroupBox *groupBox_search_and_judgement;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_contains;
    QPushButton *pushButton_indexOf_and_lastIndexOf;
    QPushButton *pushButton_endsWith_and_startsWith;
    QPushButton *pushButton_count;
    QGroupBox *groupBox_conversion_or_modification;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_insert;
    QPushButton *pushButton_trimmed_and_simplified;
    QPushButton *pushButton_remove;
    QPushButton *pushButton_replace;
    QFrame *frame_input_and_display;
    QGroupBox *groupBox_input;
    QLabel *label_str1;
    QComboBox *comboBox_str2;
    QLabel *label_str2;
    QComboBox *comboBox_str1;
    QGroupBox *groupBox_result_display;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_clear;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(840, 750);
        frame_buttons = new QFrame(Widget);
        frame_buttons->setObjectName("frame_buttons");
        frame_buttons->setGeometry(QRect(20, 20, 351, 711));
        frame_buttons->setFrameShape(QFrame::Shape::StyledPanel);
        frame_buttons->setFrameShadow(QFrame::Shadow::Raised);
        groupBox_storage_related = new QGroupBox(frame_buttons);
        groupBox_storage_related->setObjectName("groupBox_storage_related");
        groupBox_storage_related->setGeometry(QRect(10, 170, 331, 161));
        gridLayout_2 = new QGridLayout(groupBox_storage_related);
        gridLayout_2->setObjectName("gridLayout_2");
        pushButton_isNull_and_isEmpty = new QPushButton(groupBox_storage_related);
        pushButton_isNull_and_isEmpty->setObjectName("pushButton_isNull_and_isEmpty");

        gridLayout_2->addWidget(pushButton_isNull_and_isEmpty, 0, 0, 1, 1);

        pushButton_resize = new QPushButton(groupBox_storage_related);
        pushButton_resize->setObjectName("pushButton_resize");

        gridLayout_2->addWidget(pushButton_resize, 0, 1, 1, 1);

        pushButton_size_and_length = new QPushButton(groupBox_storage_related);
        pushButton_size_and_length->setObjectName("pushButton_size_and_length");

        gridLayout_2->addWidget(pushButton_size_and_length, 1, 0, 1, 1);

        pushButton_fill = new QPushButton(groupBox_storage_related);
        pushButton_fill->setObjectName("pushButton_fill");

        gridLayout_2->addWidget(pushButton_fill, 1, 1, 1, 1);

        groupBox_string_interception = new QGroupBox(frame_buttons);
        groupBox_string_interception->setObjectName("groupBox_string_interception");
        groupBox_string_interception->setGeometry(QRect(10, 0, 331, 151));
        gridLayout = new QGridLayout(groupBox_string_interception);
        gridLayout->setObjectName("gridLayout");
        pushButton_front_and_back = new QPushButton(groupBox_string_interception);
        pushButton_front_and_back->setObjectName("pushButton_front_and_back");

        gridLayout->addWidget(pushButton_front_and_back, 0, 0, 1, 1);

        pushButton_sliced = new QPushButton(groupBox_string_interception);
        pushButton_sliced->setObjectName("pushButton_sliced");

        gridLayout->addWidget(pushButton_sliced, 0, 1, 1, 1);

        pushButton_first_and_last = new QPushButton(groupBox_string_interception);
        pushButton_first_and_last->setObjectName("pushButton_first_and_last");

        gridLayout->addWidget(pushButton_first_and_last, 1, 0, 1, 1);

        pushButton_section = new QPushButton(groupBox_string_interception);
        pushButton_section->setObjectName("pushButton_section");

        gridLayout->addWidget(pushButton_section, 1, 1, 1, 1);

        groupBox_search_and_judgement = new QGroupBox(frame_buttons);
        groupBox_search_and_judgement->setObjectName("groupBox_search_and_judgement");
        groupBox_search_and_judgement->setGeometry(QRect(10, 350, 331, 161));
        gridLayout_3 = new QGridLayout(groupBox_search_and_judgement);
        gridLayout_3->setObjectName("gridLayout_3");
        pushButton_contains = new QPushButton(groupBox_search_and_judgement);
        pushButton_contains->setObjectName("pushButton_contains");

        gridLayout_3->addWidget(pushButton_contains, 0, 1, 1, 1);

        pushButton_indexOf_and_lastIndexOf = new QPushButton(groupBox_search_and_judgement);
        pushButton_indexOf_and_lastIndexOf->setObjectName("pushButton_indexOf_and_lastIndexOf");

        gridLayout_3->addWidget(pushButton_indexOf_and_lastIndexOf, 0, 0, 1, 1);

        pushButton_endsWith_and_startsWith = new QPushButton(groupBox_search_and_judgement);
        pushButton_endsWith_and_startsWith->setObjectName("pushButton_endsWith_and_startsWith");

        gridLayout_3->addWidget(pushButton_endsWith_and_startsWith, 1, 0, 1, 1);

        pushButton_count = new QPushButton(groupBox_search_and_judgement);
        pushButton_count->setObjectName("pushButton_count");

        gridLayout_3->addWidget(pushButton_count, 1, 1, 1, 1);

        groupBox_conversion_or_modification = new QGroupBox(frame_buttons);
        groupBox_conversion_or_modification->setObjectName("groupBox_conversion_or_modification");
        groupBox_conversion_or_modification->setGeometry(QRect(10, 530, 331, 161));
        gridLayout_4 = new QGridLayout(groupBox_conversion_or_modification);
        gridLayout_4->setObjectName("gridLayout_4");
        pushButton_insert = new QPushButton(groupBox_conversion_or_modification);
        pushButton_insert->setObjectName("pushButton_insert");

        gridLayout_4->addWidget(pushButton_insert, 0, 1, 1, 1);

        pushButton_trimmed_and_simplified = new QPushButton(groupBox_conversion_or_modification);
        pushButton_trimmed_and_simplified->setObjectName("pushButton_trimmed_and_simplified");

        gridLayout_4->addWidget(pushButton_trimmed_and_simplified, 0, 0, 1, 1);

        pushButton_remove = new QPushButton(groupBox_conversion_or_modification);
        pushButton_remove->setObjectName("pushButton_remove");

        gridLayout_4->addWidget(pushButton_remove, 1, 0, 1, 1);

        pushButton_replace = new QPushButton(groupBox_conversion_or_modification);
        pushButton_replace->setObjectName("pushButton_replace");

        gridLayout_4->addWidget(pushButton_replace, 1, 1, 1, 1);

        frame_input_and_display = new QFrame(Widget);
        frame_input_and_display->setObjectName("frame_input_and_display");
        frame_input_and_display->setGeometry(QRect(380, 20, 441, 711));
        frame_input_and_display->setFrameShape(QFrame::Shape::StyledPanel);
        frame_input_and_display->setFrameShadow(QFrame::Shadow::Raised);
        groupBox_input = new QGroupBox(frame_input_and_display);
        groupBox_input->setObjectName("groupBox_input");
        groupBox_input->setGeometry(QRect(10, 0, 421, 171));
        label_str1 = new QLabel(groupBox_input);
        label_str1->setObjectName("label_str1");
        label_str1->setGeometry(QRect(20, 40, 41, 31));
        comboBox_str2 = new QComboBox(groupBox_input);
        comboBox_str2->addItem(QString());
        comboBox_str2->setObjectName("comboBox_str2");
        comboBox_str2->setGeometry(QRect(70, 90, 121, 31));
        label_str2 = new QLabel(groupBox_input);
        label_str2->setObjectName("label_str2");
        label_str2->setGeometry(QRect(20, 90, 41, 31));
        comboBox_str1 = new QComboBox(groupBox_input);
        comboBox_str1->addItem(QString());
        comboBox_str1->addItem(QString());
        comboBox_str1->setObjectName("comboBox_str1");
        comboBox_str1->setGeometry(QRect(70, 40, 331, 31));
        groupBox_result_display = new QGroupBox(frame_input_and_display);
        groupBox_result_display->setObjectName("groupBox_result_display");
        groupBox_result_display->setGeometry(QRect(10, 180, 421, 511));
        gridLayout_5 = new QGridLayout(groupBox_result_display);
        gridLayout_5->setObjectName("gridLayout_5");
        pushButton_clear = new QPushButton(groupBox_result_display);
        pushButton_clear->setObjectName("pushButton_clear");

        gridLayout_5->addWidget(pushButton_clear, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(groupBox_result_display);
        plainTextEdit->setObjectName("plainTextEdit");

        gridLayout_5->addWidget(plainTextEdit, 1, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "QString\345\270\270\347\224\250\345\212\237\350\203\275", nullptr));
        groupBox_storage_related->setTitle(QCoreApplication::translate("Widget", "\345\255\230\345\202\250\347\233\270\345\205\263", nullptr));
        pushButton_isNull_and_isEmpty->setText(QCoreApplication::translate("Widget", "isNull && isEmpty", nullptr));
        pushButton_resize->setText(QCoreApplication::translate("Widget", "resize", nullptr));
        pushButton_size_and_length->setText(QCoreApplication::translate("Widget", "size && length", nullptr));
        pushButton_fill->setText(QCoreApplication::translate("Widget", "fill", nullptr));
        groupBox_string_interception->setTitle(QCoreApplication::translate("Widget", "\345\255\227\347\254\246\344\270\262\346\210\252\345\217\226", nullptr));
        pushButton_front_and_back->setText(QCoreApplication::translate("Widget", "front && back", nullptr));
        pushButton_sliced->setText(QCoreApplication::translate("Widget", "sliced *", nullptr));
        pushButton_first_and_last->setText(QCoreApplication::translate("Widget", "first && last", nullptr));
        pushButton_section->setText(QCoreApplication::translate("Widget", "section *", nullptr));
        groupBox_search_and_judgement->setTitle(QCoreApplication::translate("Widget", "\346\220\234\347\264\242\345\222\214\345\210\244\346\226\255", nullptr));
        pushButton_contains->setText(QCoreApplication::translate("Widget", "contains", nullptr));
        pushButton_indexOf_and_lastIndexOf->setText(QCoreApplication::translate("Widget", "indexOf && lastIndexOf", nullptr));
        pushButton_endsWith_and_startsWith->setText(QCoreApplication::translate("Widget", "endsWith && startsWith", nullptr));
        pushButton_count->setText(QCoreApplication::translate("Widget", "count", nullptr));
        groupBox_conversion_or_modification->setTitle(QCoreApplication::translate("Widget", "\350\275\254\346\215\242\346\210\226\344\277\256\346\224\271", nullptr));
        pushButton_insert->setText(QCoreApplication::translate("Widget", "insert", nullptr));
        pushButton_trimmed_and_simplified->setText(QCoreApplication::translate("Widget", "trimmed && simplified", nullptr));
        pushButton_remove->setText(QCoreApplication::translate("Widget", "remove", nullptr));
        pushButton_replace->setText(QCoreApplication::translate("Widget", "replace", nullptr));
        groupBox_input->setTitle(QCoreApplication::translate("Widget", "\350\276\223\345\205\245", nullptr));
        label_str1->setText(QCoreApplication::translate("Widget", "str1", nullptr));
        comboBox_str2->setItemText(0, QCoreApplication::translate("Widget", "/", nullptr));

        label_str2->setText(QCoreApplication::translate("Widget", "str2", nullptr));
        comboBox_str1->setItemText(0, QCoreApplication::translate("Widget", "~/source/Qt/Application/cpp/learning", nullptr));
        comboBox_str1->setItemText(1, QCoreApplication::translate("Widget", "~/test.cpp", nullptr));

        groupBox_result_display->setTitle(QCoreApplication::translate("Widget", "\347\273\223\346\236\234\346\230\276\347\244\272", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
