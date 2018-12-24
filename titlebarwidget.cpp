#include "titlebarwidget.h"

/***************** pushbutton *************************************************************/

TitleBarButton::TitleBarButton(QWidget *parent):QPushButton(parent)
{

}

void TitleBarButton::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    QString pixmapPath;

    switch (m_status) {
    case NORMAL:
        pixmapPath = m_imagPath+"_normal";
        break;
    case HOVER:
        pixmapPath = m_imagPath+"_hover";
        break;
    default:
        pixmapPath = m_imagPath+"_normal";
        break;
    }

    paint.drawPixmap(rect(), QPixmap(pixmapPath));

    QWidget::paintEvent(event);
}

void TitleBarButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        is_pressed = true;

        m_status = HOVER;
        update();
    }
}

void TitleBarButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton && is_pressed){
        is_pressed = false;

        m_status = NORMAL;

        emit clicked();
    }
}

void TitleBarButton::enterEvent(QEvent *event)
{
    is_pressed = false;

    m_status = HOVER;
}

void TitleBarButton::leaveEvent(QEvent *event)
{
    is_pressed = false;

    m_status = NORMAL;
}

void TitleBarButton::setBackground(const QString &path)
{
    m_imagPath = path;

//    this->setFixedSize(QPixmap("icon/min_hover").size());
    this->setFixedSize(QSize(24,24));

}

/******************* title bar ***********************************************************/

TitleBarWidget::TitleBarWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *mainLayout = new QHBoxLayout;

    m_pLabelIcon = new QLabel(this);
    m_pLabelTitle = new QLabel(this);

//    QByteArray htmlstr = "<style>a{text-decoration:none}</style><a href = www.ebox.com><font color=red style='font-size:16px'> www.lingzhilab.com</font></a>";
//    QLabel *labeWeb = new QLabel(this);
//    labeWeb->setText(QString::fromLocal8Bit(htmlstr));
//    labeWeb->setOpenExternalLinks(true);

    m_pMenuButton = new TitleBarButton(this);
    m_pMenuButton->setBackground(":/icon/menu");
    m_pMenuButton->setToolTip(tr("主菜单"));

    m_pMinButton = new TitleBarButton(this);
    m_pMinButton->setBackground(":/icon/min");
    m_pMinButton->setToolTip(tr("最小化"));

//    m_pRestoreButton = new TitleBarButton(this);

    m_pMaxButton = new TitleBarButton(this);
    m_pMaxButton->setBackground(":/icon/max");

    m_pCloseButton = new TitleBarButton(this);
    m_pCloseButton->setBackground(":/icon/close");
    m_pCloseButton->setToolTip(tr("关闭"));

    mainLayout->addWidget(m_pLabelIcon);
    mainLayout->addWidget(m_pLabelTitle);
    mainLayout->addSpacing(60);
//    mainLayout->addWidget(labeWeb);

    mainLayout->addStretch();

    mainLayout->addWidget(m_pMenuButton);
    mainLayout->addWidget(m_pMinButton);
    mainLayout->addWidget(m_pMaxButton);
    mainLayout->addWidget(m_pCloseButton);

    mainLayout->setSpacing(10);
    mainLayout->setMargin(6);

    this->setLayout(mainLayout);

    //stylesheet
//    this->setStyleSheet("background-color:rgb(94,233,12)");

    connect(m_pCloseButton, &QPushButton::clicked, this, &TitleBarWidget::onClosebtnClicked);
    connect(m_pMenuButton,&TitleBarButton::clicked,this,&TitleBarWidget::menuButtonClicked);
    connect(m_pMaxButton,&TitleBarButton::clicked,this,&TitleBarWidget::onMaxbuttonClicked);
    connect(m_pMinButton,&TitleBarButton::clicked,this, &TitleBarWidget::onMinbuttonClicked);
}

void TitleBarWidget::setTitleIcon(QString iconPath, QSize size)
{
    QImage *img = new QImage;
    img->load(iconPath);
    QImage *imaScaled = new QImage;
    *imaScaled = img->scaled(35,35,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    m_pLabelIcon->setPixmap(QPixmap::fromImage(*imaScaled));
}

void TitleBarWidget::setTitleName(QString text, int size)
{
    QFont font("Microsoft YaHei", 11,63);

    m_pLabelTitle->setFont(font);

    QPalette pa;
    pa.setColor(QPalette::WindowText, QColor(0,0,60,220));
    m_pLabelTitle->setPalette(pa);

    m_pLabelTitle->setText(text);
}

void TitleBarWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen(QColor(65,65,65),1);

    painter.setPen(pen);
    painter.setBrush(Qt::white);
    painter.drawRect(rect());

    painter.drawLine(this->width()-1,0,this->width()-1,this->height());
}

void TitleBarWidget::onMaxbuttonClicked()
{
    QWidget *p_wind = this->window();

    if(p_wind->isTopLevel()){
        p_wind->isMaximized()?p_wind->showNormal():p_wind->showMaximized();
    }
}

void TitleBarWidget::onMinbuttonClicked()
{
    QWidget *p_wind = this->window();

    if(p_wind->isTopLevel()){
        p_wind->showMinimized();
    }
}

void TitleBarWidget::menuButtonClicked()
{
    qDebug()<<"menu button clicked";

    QMenu *MainMenu = new QMenu(this);

    QAction *actSetting = new QAction(tr("设置"));
    QAction *actAbout = new QAction(tr("关于"));

    MainMenu->addAction(actSetting);
    MainMenu->addSeparator();
    MainMenu->addAction(actAbout);

    m_pMenuButton->setMenu(MainMenu);

    /************** 菜单信号槽 ********************************/
    connect(actSetting, &QAction::triggered, this, &TitleBarWidget::onMenuSettingClicked);
    connect(actAbout, &QAction::triggered, this, &TitleBarWidget::onMenuAboutClicked);

    /*********   菜单执行 *****************/
    MainMenu->exec(cursor().pos());

}

void TitleBarWidget::onMenuSettingClicked()
{

}

void TitleBarWidget::onMenuAboutClicked()
{
//    qDebug()<<__FUNCTION__;

    AboutDialog *aboutDlg = new AboutDialog(this);

    aboutDlg->exec();
}


void TitleBarWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    emit m_pMaxButton->clicked();
}

void TitleBarWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_is_mousePressed = true;

        m_posStartMove = event->pos();
    }

    QWidget::mousePressEvent(event);
}

void TitleBarWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_is_mousePressed = false;

    QWidget::mouseReleaseEvent(event);
}

void TitleBarWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(m_is_mousePressed){

        if(this->window()->isMaximized()){
            return QWidget::mouseMoveEvent(event);
        }

       this->parentWidget()->move(event->pos()-m_posStartMove+this->parentWidget()->pos());
    }

    QWidget::mouseMoveEvent(event);
}

bool TitleBarWidget::eventFilter(QObject *watched, QEvent *event)
{
    switch (event->type()) {
    case QEvent::WindowStateChange:
    case QEvent::Resize:
        updateMaximize();
        return true;
        break;
    default:
        break;
    }

    QWidget::eventFilter(watched,event);
}

void TitleBarWidget::updateMaximize()
{
    QWidget *p_wind = this->window();

    if(p_wind->isTopLevel()){
        bool bMaximize = p_wind->isMaximized();

        if(bMaximize){
            m_pMaxButton->setToolTip(tr("还原"));
            m_pMaxButton->setProperty("maximizeProperty", "restore");
        }else{
            m_pMaxButton->setToolTip(tr("最大化"));
            m_pMaxButton->setProperty("maximizeProperty", "Maximize");
        }
    }
}
