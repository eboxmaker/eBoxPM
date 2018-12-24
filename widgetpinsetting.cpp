#include "widgetpinsetting.h"
#include "ui_widgetpinsetting.h"

WidgetPinSetting::WidgetPinSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetPinSetting)
{
    ui->setupUi(this);
}

WidgetPinSetting::~WidgetPinSetting()
{
    delete ui;
}
