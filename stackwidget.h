#ifndef LEFTWIDGET_H
#define LEFTWIDGET_H

#include "globalinc.h"

enum buttonPressedType{
    btnWelcomePressed = 0,
    btnCodePressed,
    btnDesignPressed,
    btnSerialPressed
};

class stackWidget : public QWidget
{
    Q_OBJECT
public:
    explicit stackWidget(QWidget *parent = nullptr);

signals:
    void buttonPressed(int index);

public slots:
    void onWelcombtnClick();
    void onCodebtnClick();
    void onDesignbtnClick();
    void onSerialbtnClick();

private:
    QToolButton *m_pButtonStarted;
    QToolButton *m_pButtonPinSetting;
    QToolButton *m_pButtonClockSetting;
    QToolButton *m_pButtonToolBox;


private:
    void paintEvent(QPaintEvent *event);
};

#endif // LEFTWIDGET_H
