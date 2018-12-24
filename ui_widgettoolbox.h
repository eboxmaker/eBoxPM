/********************************************************************************
** Form generated from reading UI file 'widgettoolbox.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETTOOLBOX_H
#define UI_WIDGETTOOLBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetToolBox
{
public:
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QWidget *WidgetToolBox)
    {
        if (WidgetToolBox->objectName().isEmpty())
            WidgetToolBox->setObjectName(QStringLiteral("WidgetToolBox"));
        WidgetToolBox->resize(400, 300);
        label = new QLabel(WidgetToolBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 72, 15));
        comboBox = new QComboBox(WidgetToolBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(80, 110, 231, 22));

        retranslateUi(WidgetToolBox);

        QMetaObject::connectSlotsByName(WidgetToolBox);
    } // setupUi

    void retranslateUi(QWidget *WidgetToolBox)
    {
        WidgetToolBox->setWindowTitle(QApplication::translate("WidgetToolBox", "Form", nullptr));
        label->setText(QApplication::translate("WidgetToolBox", "tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetToolBox: public Ui_WidgetToolBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETTOOLBOX_H
