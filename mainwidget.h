/**********************************************************************
 * 主界面文件
 *
 * ********************************************************************/

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "globalinc.h"

#include "titlebarwidget.h"
#include "stackwidget.h"

#include "widgetstart.h"
#include "widgetclocksetting.h"
#include "widgetpinsetting.h"
#include "widgettoolbox.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();


private:
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWidget *ui;

private:
    TitleBarWidget *m_pTitleBarWidget;
    stackWidget *m_pstackWidget;
    QStackedWidget *m_pCentralWidget;
    QStatusBar *m_pStatusBar;
    QLabel *m_pStatusInfo;

private slots:


signals:


};

#endif // MAINWIDGET_H
