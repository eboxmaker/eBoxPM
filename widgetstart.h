#ifndef WIDGETSTART_H
#define WIDGETSTART_H

#include <QStandardItemModel>
#include <QTableWidget>
#include <QWidget>

namespace Ui {
class WidgetStart;
}

class WidgetStart : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetStart(QWidget *parent = 0);
    ~WidgetStart();
    QStandardItemModel *LoadJsonFile(QString FileFullName);
    void UpdateMcuComboBox(QStandardItemModel *modle);


private slots:
    void on_WidgetStart_windowIconChanged(const QIcon &icon);

    void on_WidgetStart_customContextMenuRequested(const QPoint &pos);


    void on_cbMCUname_editTextChanged(const QString &arg1);

    void on_cbMcuName_currentTextChanged(const QString &arg1);

    void on_btnMakeConfig_clicked();

private:
    Ui::WidgetStart *ui;
    QStandardItemModel *modle = new QStandardItemModel();
};

#endif // WIDGETSTART_H
