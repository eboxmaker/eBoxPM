/********************************************************************************
** Form generated from reading UI file 'widgetclocksetting.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETCLOCKSETTING_H
#define UI_WIDGETCLOCKSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetClockSetting
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;

    void setupUi(QWidget *WidgetClockSetting)
    {
        if (WidgetClockSetting->objectName().isEmpty())
            WidgetClockSetting->setObjectName(QStringLiteral("WidgetClockSetting"));
        WidgetClockSetting->resize(400, 300);
        label = new QLabel(WidgetClockSetting);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 110, 72, 15));
        label_2 = new QLabel(WidgetClockSetting);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 120, 72, 15));
        comboBox = new QComboBox(WidgetClockSetting);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(130, 160, 69, 22));

        retranslateUi(WidgetClockSetting);

        QMetaObject::connectSlotsByName(WidgetClockSetting);
    } // setupUi

    void retranslateUi(QWidget *WidgetClockSetting)
    {
        WidgetClockSetting->setWindowTitle(QApplication::translate("WidgetClockSetting", "Form", nullptr));
        label->setText(QApplication::translate("WidgetClockSetting", "clockset", nullptr));
        label_2->setText(QApplication::translate("WidgetClockSetting", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetClockSetting: public Ui_WidgetClockSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETCLOCKSETTING_H
