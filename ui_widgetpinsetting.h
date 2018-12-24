/********************************************************************************
** Form generated from reading UI file 'widgetpinsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETPINSETTING_H
#define UI_WIDGETPINSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPinSetting
{
public:
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QWidget *WidgetPinSetting)
    {
        if (WidgetPinSetting->objectName().isEmpty())
            WidgetPinSetting->setObjectName(QStringLiteral("WidgetPinSetting"));
        WidgetPinSetting->resize(400, 300);
        label = new QLabel(WidgetPinSetting);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 140, 72, 15));
        comboBox = new QComboBox(WidgetPinSetting);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(210, 110, 69, 22));

        retranslateUi(WidgetPinSetting);

        QMetaObject::connectSlotsByName(WidgetPinSetting);
    } // setupUi

    void retranslateUi(QWidget *WidgetPinSetting)
    {
        WidgetPinSetting->setWindowTitle(QApplication::translate("WidgetPinSetting", "Form", nullptr));
        label->setText(QApplication::translate("WidgetPinSetting", "pinset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPinSetting: public Ui_WidgetPinSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETPINSETTING_H
