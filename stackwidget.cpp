#include "stackwidget.h"

#define ICON_WIDTH 40
#define ICON_HEIGHT 40

#define BUTTON_HEIGHT 60
#define BUTTON_WIDTH  100

stackWidget::stackWidget(QWidget *parent) : QWidget(parent)
{
//    this->setFixedWidth(80);

    //这里不用，使用paintEvent中绘制背景
//    this->setStyleSheet("QWidget{background-color:rgb(192,217,241)};");

    QHBoxLayout *layout = new QHBoxLayout;

    this->setStyleSheet("QToolButton{\
                                    font: 50 10pt;\
                                    color:white;\
                                    }\n\
                         QToolButton:hover{\
                                    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, \
                                                stop:0 rgb(120,120,120), \
                                                stop: 0.6 rgb(80,80,80),\
                                                stop: 1 rgb(40,40,40));\
                                    }\n\
                         QToolButton:checked{\
                                    color:white;\
                                    background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, \
                                                               stop:0 rgb(120,120,120), \
                                                               stop: 0.3 rgb(80,80,80),\
                                                               stop: 1 rgb(40,40,40));\
                                    border-style:solid;\
                                    border-width:0px 0px 0px 0px;\
                                    border-color:rgb(131,131,131);\
                                    }\n\
                                    ");


    m_pButtonStarted = new QToolButton(this);
    m_pButtonStarted->setText(tr("开始"));
    m_pButtonStarted->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_pButtonStarted->setAutoRaise(true);
    m_pButtonStarted->setIcon(QPixmap(":/icon/logo_125h"));
    m_pButtonStarted->setFixedWidth(BUTTON_WIDTH);
    m_pButtonStarted->setIconSize(QSize(ICON_WIDTH,ICON_HEIGHT));

    m_pButtonPinSetting = new QToolButton;
    m_pButtonPinSetting->setText(tr("引脚配置"));
    m_pButtonPinSetting->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_pButtonPinSetting->setAutoRaise(true);
    m_pButtonPinSetting->setIcon(QPixmap(":/icon/gpio_item"));
    m_pButtonPinSetting->setFixedWidth(BUTTON_WIDTH);
    m_pButtonPinSetting->setIconSize(QSize(ICON_WIDTH,ICON_HEIGHT));

    m_pButtonClockSetting = new QToolButton;
    m_pButtonClockSetting->setText(tr("时钟设置"));
    m_pButtonClockSetting->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_pButtonClockSetting->setAutoRaise(true);
    m_pButtonClockSetting->setIcon(QPixmap(":/icon/clock_item"));
    m_pButtonClockSetting->setFixedWidth(BUTTON_WIDTH);
    m_pButtonClockSetting->setIconSize(QSize(ICON_WIDTH,ICON_HEIGHT));

    m_pButtonToolBox = new QToolButton;
    m_pButtonToolBox->setText(tr("工具"));
    m_pButtonToolBox->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_pButtonToolBox->setAutoRaise(true);
    m_pButtonToolBox->setIcon(QPixmap(":/icon/tool_item"));
    m_pButtonToolBox->setFixedWidth(BUTTON_WIDTH);
    m_pButtonToolBox->setIconSize(QSize(ICON_WIDTH,ICON_HEIGHT));

    m_pButtonStarted->setCheckable(true);
    m_pButtonPinSetting->setCheckable(true);
    m_pButtonClockSetting->setCheckable(true);
    m_pButtonToolBox->setCheckable(true);

    m_pButtonStarted->setChecked(true);

    layout->addSpacing(20);
    layout->addWidget(m_pButtonStarted);
    layout->addWidget(m_pButtonPinSetting);
    layout->addWidget(m_pButtonClockSetting);
    layout->addWidget(m_pButtonToolBox);

    layout->setMargin(0);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    layout->addStretch();

    connect(m_pButtonStarted, &QToolButton::clicked, this, &stackWidget::onWelcombtnClick);
    connect(m_pButtonPinSetting, &QToolButton::clicked, this, &stackWidget::onCodebtnClick);
    connect(m_pButtonClockSetting, &QToolButton::clicked, this, &stackWidget::onDesignbtnClick);
    connect(m_pButtonToolBox, &QToolButton::clicked, this, &stackWidget::onSerialbtnClick);

    this->setLayout(layout);
}

void stackWidget::paintEvent(QPaintEvent *event)
{

    //绘制背景色
    QPainter painter(this);

//    QPen pen(QColor(78,78,78),1);//工具栏和菜单栏分隔
//    painter.setPen(pen);
//    painter.drawLine(0,1,this->width(),1);

    QLinearGradient linear(0,0,0,rect().height());
    linear.setColorAt(0, QColor(131,131,131));
    linear.setColorAt(1, QColor(64,64,64));
    linear.setSpread(QGradient::PadSpread);

    painter.setPen(Qt::NoPen);

    painter.setBrush(linear);

    painter.drawRect(rect().x(),rect().y(), rect().width(), rect().height());
}

void stackWidget::onWelcombtnClick()
{
    qDebug()<<"welcome 页面该显示了";

    m_pButtonStarted->setChecked(true);
    m_pButtonPinSetting->setChecked(false);
    m_pButtonClockSetting->setChecked(false);
    m_pButtonToolBox->setChecked(false);

    emit buttonPressed(btnWelcomePressed);
}

void stackWidget::onCodebtnClick()
{
    qDebug()<<"code该显示了";

    m_pButtonStarted->setChecked(false);
    m_pButtonPinSetting->setChecked(true);
    m_pButtonClockSetting->setChecked(false);
    m_pButtonToolBox->setChecked(false);

    emit buttonPressed(btnCodePressed);
}

void stackWidget::onDesignbtnClick()
{
    qDebug()<<"design页面该显示了";

    m_pButtonStarted->setChecked(false);
    m_pButtonPinSetting->setChecked(false);
    m_pButtonClockSetting->setChecked(true);
    m_pButtonToolBox->setChecked(false);

    emit buttonPressed(btnDesignPressed);
}

void stackWidget::onSerialbtnClick()
{
    qDebug()<<"serial调试页面该显示了";

    m_pButtonStarted->setChecked(false);
    m_pButtonPinSetting->setChecked(false);
    m_pButtonClockSetting->setChecked(false);
    m_pButtonToolBox->setChecked(true);

    emit buttonPressed(btnSerialPressed);

}

