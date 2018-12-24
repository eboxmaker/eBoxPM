#ifndef WIDGETPINSETTING_H
#define WIDGETPINSETTING_H

#include <QWidget>

namespace Ui {
class WidgetPinSetting;
}

class WidgetPinSetting : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetPinSetting(QWidget *parent = 0);
    ~WidgetPinSetting();

private:
    Ui::WidgetPinSetting *ui;
};

#endif // WIDGETPINSETTING_H
