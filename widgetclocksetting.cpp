#include "widgetclocksetting.h"
#include "ui_widgetclocksetting.h"

WidgetClockSetting::WidgetClockSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetClockSetting)
{
    ui->setupUi(this);
}

WidgetClockSetting::~WidgetClockSetting()
{
    delete ui;
}
