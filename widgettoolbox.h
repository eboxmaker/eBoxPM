#ifndef WIDGETTOOLBOX_H
#define WIDGETTOOLBOX_H

#include <QWidget>

namespace Ui {
class WidgetToolBox;
}

class WidgetToolBox : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetToolBox(QWidget *parent = 0);
    ~WidgetToolBox();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::WidgetToolBox *ui;
};

#endif // WIDGETTOOLBOX_H
