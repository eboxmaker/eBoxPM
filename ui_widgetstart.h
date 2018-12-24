/********************************************************************************
** Form generated from reading UI file 'widgetstart.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSTART_H
#define UI_WIDGETSTART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetStart
{
public:
    QLabel *lbMCUName;
    QTableView *tbvMCUs;
    QComboBox *cbMcuName;
    QPushButton *btnMakeConfig;

    void setupUi(QWidget *WidgetStart)
    {
        if (WidgetStart->objectName().isEmpty())
            WidgetStart->setObjectName(QStringLiteral("WidgetStart"));
        WidgetStart->resize(844, 433);
        lbMCUName = new QLabel(WidgetStart);
        lbMCUName->setObjectName(QStringLiteral("lbMCUName"));
        lbMCUName->setGeometry(QRect(10, 50, 54, 16));
        tbvMCUs = new QTableView(WidgetStart);
        tbvMCUs->setObjectName(QStringLiteral("tbvMCUs"));
        tbvMCUs->setGeometry(QRect(0, 120, 831, 192));
        cbMcuName = new QComboBox(WidgetStart);
        cbMcuName->setObjectName(QStringLiteral("cbMcuName"));
        cbMcuName->setGeometry(QRect(60, 50, 141, 22));
        cbMcuName->setEditable(true);
        btnMakeConfig = new QPushButton(WidgetStart);
        btnMakeConfig->setObjectName(QStringLiteral("btnMakeConfig"));
        btnMakeConfig->setGeometry(QRect(680, 50, 111, 23));

        retranslateUi(WidgetStart);

        QMetaObject::connectSlotsByName(WidgetStart);
    } // setupUi

    void retranslateUi(QWidget *WidgetStart)
    {
        WidgetStart->setWindowTitle(QApplication::translate("WidgetStart", "Form", nullptr));
        lbMCUName->setText(QApplication::translate("WidgetStart", "MCU\345\220\215\347\247\260", nullptr));
        btnMakeConfig->setText(QApplication::translate("WidgetStart", "\347\224\237\346\210\220mcuconfig", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetStart: public Ui_WidgetStart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSTART_H
