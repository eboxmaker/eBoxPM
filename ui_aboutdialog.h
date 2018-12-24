/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_logo;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_info;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QStringLiteral("AboutDialog"));
        AboutDialog->resize(611, 276);
        horizontalLayout_2 = new QHBoxLayout(AboutDialog);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_logo = new QLabel(AboutDialog);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setMinimumSize(QSize(100, 0));
        label_logo->setMaximumSize(QSize(500, 375));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/images/resource/logo-big.png")));
        label_logo->setScaledContents(false);
        label_logo->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_logo);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_info = new QLabel(AboutDialog);
        label_info->setObjectName(QStringLiteral("label_info"));

        verticalLayout->addWidget(label_info);

        verticalSpacer_2 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "\345\205\263\344\272\216\346\234\254\350\275\257\344\273\266", nullptr));
        label_logo->setText(QString());
        label_info->setText(QApplication::translate("AboutDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\234\254\350\275\257\344\273\266\344\270\223\347\224\250\344\272\216ebox\345\271\263\345\217\260\345\267\245\347\250\213\351\205\215\347\275\256\357\274\214\345\242\236\345\274\272ebox\345\271\263\345\217\260\347\232\204\346\230\223\347\224\250\346\200\247\343\200\202</span></p><p><a href=\"www.wandianlian.com\"><span style=\" font-size:14pt; text-decoration: underline; color:#000000;\">\345\256\230\346\226\271\347\275\221\347\253\231\357\274\232</span></a><a href=\"www.lingzhilab.com\"><span style=\" text-decoration: underline; color:#0000ff;\">www.ebox.com</span></a></p><p><br/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
