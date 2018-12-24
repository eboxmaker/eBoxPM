#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/icon/logo_35h"));
    this->setWindowFlags(Qt::Dialog|Qt::WindowCloseButtonHint);

    ui->label_logo->setMaximumHeight(300);
    ui->label_logo->setMaximumWidth(300);

    ui->label_logo->setPixmap(QPixmap(":/icon/logo_125h"));

    ui->label_info->setOpenExternalLinks(true);

}

AboutDialog::~AboutDialog()
{
    delete ui;
}
