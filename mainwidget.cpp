#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    QString applicationTitle = tr("eboxPM v0.01");
    QString applicationIconPath=":/icon/logo_35h";

/*********************** 默认窗口设置 *******************************************/

//    this->resize(800,600);
    QRect desktopRect = QApplication::desktop()->availableGeometry();
    this->resize(desktopRect.width()*0.6, desktopRect.height()*0.8);
//    this->setWindowState(Qt::WindowMaximized);

/*********************** 隐藏标题栏，使用自定义标题栏 *******************************/

    this->setWindowFlags(windowFlags()|Qt::FramelessWindowHint);
    m_pTitleBarWidget = new TitleBarWidget(this);
    installEventFilter(m_pTitleBarWidget);
    m_pTitleBarWidget->setTitleIcon(applicationIconPath);
    m_pTitleBarWidget->setTitleName(applicationTitle);

    //在托盘显示名字和图标，没有这个就会显示MainWidget默认名字
    this->setWindowTitle(applicationTitle);
    this->setWindowIcon(QIcon(applicationIconPath));

    this->setMouseTracking(true);
    this->setMinimumSize(QSize(800,500));


    connect(m_pTitleBarWidget, &TitleBarWidget::onClosebtnClicked, this, &MainWidget::close);


/*********************** stack 选择器 ... ********************************/
        m_pstackWidget = new stackWidget(this);

/********************* 中间窗口：stack进行切换显示 **********************************************/
    m_pCentralWidget = new QStackedWidget(this);

    WidgetStart *startWidget = new WidgetStart(this);
    WidgetPinSetting *pinSettingWidget = new WidgetPinSetting(this);
    WidgetClockSetting *clockSettingWidget = new WidgetClockSetting(this);
    WidgetToolBox *toolboxWidget = new WidgetToolBox(this);

    m_pCentralWidget->addWidget(startWidget);
    m_pCentralWidget->addWidget(pinSettingWidget);
    m_pCentralWidget->addWidget(clockSettingWidget);
    m_pCentralWidget->addWidget(toolboxWidget);

    m_pCentralWidget->setCurrentIndex(0);

    QVBoxLayout *centralLayout = new QVBoxLayout;
    centralLayout->addWidget(m_pstackWidget);
    centralLayout->addWidget(m_pCentralWidget);
    centralLayout->setSpacing(0);

    connect(m_pstackWidget,SIGNAL(buttonPressed(int)), m_pCentralWidget, SLOT(setCurrentIndex(int)));

/*********************** 输出窗口 *********************************************/


/*********************** 状态栏 ***********************************************/
    m_pStatusBar = new QStatusBar(this);
    m_pStatusBar->setStyleSheet("background-color:rgb(75,75,75)");

    m_pStatusInfo = new QLabel(this);

    m_pStatusInfo->setText(tr("就绪"));

    m_pStatusBar->addWidget(m_pStatusInfo);

/*********************** 整个窗口布局 *****************************************/
    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(m_pTitleBarWidget);

    mainLayout->addLayout(centralLayout);

    mainLayout->addWidget(m_pStatusBar);

    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    this->setLayout(mainLayout);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);

    //窗体外框线
    paint.setPen(QPen(QColor(75,75,75),1));

    paint.drawLine(rect().left(),0,rect().left(),rect().bottom());
    paint.drawLine(rect().right(),0,rect().right(), rect().bottom());

    QWidget::paintEvent(event);
}
