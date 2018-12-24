#include "widgettoolbox.h"
#include "ui_widgettoolbox.h"

WidgetToolBox::WidgetToolBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetToolBox)
{
    ui->setupUi(this);
}

WidgetToolBox::~WidgetToolBox()
{
    delete ui;
}

void WidgetToolBox::on_comboBox_currentTextChanged(const QString &arg1)
{

}
