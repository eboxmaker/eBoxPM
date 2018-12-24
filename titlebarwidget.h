#ifndef TITLEBARWIDGET_H
#define TITLEBARWIDGET_H

#include "globalinc.h"
#include "aboutdialog.h"

class TitleBarButton:public QPushButton
{
    Q_OBJECT
public:
    explicit TitleBarButton(QWidget *parent = 0);

    enum BtnStatus{NORMAL, HOVER};

    void setBackground(const QString &path);


protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

private:
    BtnStatus m_status;
    bool is_pressed;
    QString m_imagPath;
};

class TitleBarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBarWidget(QWidget *parent = nullptr);

    void setTitleIcon(QString iconPath, QSize size = QSize(30,30));
    void setTitleName(QString text, int size = 9);

signals:
    void onClosebtnClicked();

public slots:
    void menuButtonClicked();
    void onMaxbuttonClicked();
    void onMinbuttonClicked();

    void onMenuSettingClicked();
    void onMenuAboutClicked();

private:
    void paintEvent(QPaintEvent *event);

    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    bool eventFilter(QObject *watched, QEvent *event);

private:
    void updateMaximize();

private:
    QLabel *m_pLabelIcon;
    QLabel *m_pLabelTitle;
    TitleBarButton *m_pMinButton;
//    TitleBarButton *m_pRestoreButton;
    TitleBarButton *m_pMaxButton;
    TitleBarButton *m_pCloseButton;

    TitleBarButton *m_pMenuButton;

    QPoint m_posStartMove;
    bool m_is_mousePressed;
};

#endif // TITLEBARWIDGET_H
