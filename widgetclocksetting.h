#ifndef WIDGETCLOCKSETTING_H
#define WIDGETCLOCKSETTING_H

#include <QWidget>

namespace Ui {
class WidgetClockSetting;
}

class WidgetClockSetting : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetClockSetting(QWidget *parent = 0);
    ~WidgetClockSetting();

private:
    Ui::WidgetClockSetting *ui;
};

#endif // WIDGETCLOCKSETTING_H
