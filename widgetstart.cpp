#include "widgetstart.h"
#include "ui_widgetstart.h"


#include "QString"
#include "QJsonArray"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonValue"
#include "configfilehelper.h"

#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTableWidget>
#include <QTextStream>

class McuInfo
{
    public:
        QString RPN;
        QString package;
        QString flash;
        QString ram;
        QString iONb;
        QString frequency;
};


WidgetStart::WidgetStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetStart)
{
    ui->setupUi(this);
    ui->tbvMCUs->setSelectionBehavior(QAbstractItemView::SelectRows);

    modle = LoadJsonFile("C:\\Users\\Administrator\\Desktop\\ebox-pm-v0.01\\debug\\mcusFeaturesAndDescription.json");
   // UpdateMcuComboBox(modle);
    ui->tbvMCUs->setModel(modle);
    ui->tbvMCUs->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

WidgetStart::~WidgetStart()
{
    delete ui;
}
void WidgetStart::UpdateMcuComboBox(QStandardItemModel *modle)
{
    for(int i = 1; i < modle->rowCount();i++)
    {
        ui->cbMcuName->addItem(modle->item(i,0)->text());
    }
    ui->cbMcuName->clearEditText();
}

QStandardItemModel *WidgetStart::LoadJsonFile(QString FileFullName)
{
    QStandardItemModel *modle = new QStandardItemModel();
    QJsonObject obj;
    QString str;
    QFile file(FileFullName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        QMessageBox::warning(this,"Warnning","can't open",QMessageBox::Yes);

    }
    QTextStream in(&file);
    str=in.readAll();


    modle->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("Name")));
    modle->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("package")));
    modle->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("flash")));
    modle->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("ram")));
    modle->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("iONb")));
    modle->setHorizontalHeaderItem(5,new QStandardItem(QObject::tr("frequency")));
    QByteArray buf = str.toUtf8();
    QJsonDocument jdoc = QJsonDocument::fromJson(buf);

    if(jdoc.isObject())
    {
        QJsonObject jo = jdoc.object();

        /* 打印商品信息 */
        //QJsonValue value = jo.value("TXTString");
        //QJsonObject PrintMsg = value.toObject();

        //QJsonObject jo.["TXTString"].toObject();

       // MakePrtMsg(PrintMsg);
       QJsonValue value = jo.value("MCUs");           //获取value
       QJsonArray MCUs = value.toArray();             //value转换
        int counter = 0;
       for(int i = 0 ; i < MCUs.count(); i++)
       {

            QJsonValue x1 = MCUs.at(i);
            QJsonObject obj1 = x1.toObject();

            QJsonValue packageValue = obj1.value("subpackages");           //获取value
            QJsonArray package = packageValue.toArray();             //value转换
            for(int j = 0; j < package.count(); j++)
            {
                McuInfo mcuInfo;
                counter++;
                QJsonValue x2 = package.at(j);
                QJsonObject obj2 = x2.toObject();


                mcuInfo.RPN = obj1["RPN"].toString();
                mcuInfo.package= obj2["package"].toString();
                mcuInfo.flash = obj1["flash"].toString();
                mcuInfo.ram = obj1["ram"].toString();
                mcuInfo.iONb = obj2["iONb"].toString();
                mcuInfo.frequency = obj1["frequency"].toString();
                modle->setItem(counter,0,new QStandardItem(mcuInfo.RPN));
                modle->setItem(counter,1,new QStandardItem(mcuInfo.package));
                modle->setItem(counter,2,new QStandardItem(mcuInfo.flash));
                modle->setItem(counter,3,new QStandardItem(mcuInfo.ram));
                modle->setItem(counter,4,new QStandardItem(mcuInfo.iONb));
                modle->setItem(counter,5,new QStandardItem(mcuInfo.frequency));
//                qDebug()<<counter<<s1.toStdString().c_str()<<s2<<s3<<s4<<s5<<s6<<endl;
            }
       }

    }
    file.close();
    return modle;

}


void WidgetStart::on_cbMcuName_currentTextChanged(const QString &arg1)
{
    QString str = ui->cbMcuName->currentText() ;

    qDebug()<<"current edit:"<<str;

   QList<QStandardItem*> ItemList  =  modle->findItems(str,Qt::MatchStartsWith);

    for(int i = 0; i < modle->rowCount(); i++){
        ui->tbvMCUs->setRowHidden(i,true);
     }

    if(!ItemList.isEmpty()){
        for(int i=0; i<ItemList.count(); i++){
            ui->tbvMCUs->setRowHidden(ItemList.at(i)->row(),false);
        }
    }

}

void WidgetStart::on_btnMakeConfig_clicked()
{
    ConfigFileHelper  *cfh = new ConfigFileHelper();
    cfh->LoadFile("C:\\Users\\Administrator\\Desktop\\ebox-pm-v0.01\\debug\\mcu_config.h");
    for(int i = 0; i < cfh->data.count(); i++)
        qDebug()<<cfh->data[i];
    McuInfo mcuInfo;
    int row = ui->tbvMCUs->currentIndex().row();

    //mcuInfo.RPN = ui->tbvMCUs->data(row,0);
    QStringList str;
    QVariant data[7];
    for(int i = 0 ; i < 6; i++)
    {
        QModelIndex index = modle->index(row,i);//选中行第一列的内容
        data[i] = modle->data(index);
        qDebug()<<data[i].toString();
    }
    str.append("#define STM32_TYPE     " + data[0].toString());
    str.append("#define STM32_FLASH    " + data[2].toString());
    str.append("#define STM32_RAM1     " + data[3].toString());
    str.append("#define STM32_PINS     " + data[4].toString());
    str.append("#define STM32_COMPANY  \"ST\"");
    str.append("#define HSE_VALUE      ((uint32_t)8000000)");


    QString strType = data[0].toString().mid(0,7);

    cfh->ModifyPosition(1,str);
    QStringList str2;
    if (strType == "STM32F1") {
        str2.append("#include \"stm32f10x.h\"");
    }
    else if (strType == "STM32F2") {
        str2.append("#include \"stm32f20x.h\"");
    }
    else if (strType == "STM32F3") {
        str2.append("#include \"stm32f30x.h\"");
    }
    else if (strType == "STM32F4") {
        str2.append("#include \"stm32f4xx.h\"");
    }
    else  {
        str2.append("#include \"failed.h\"");
    }
    //需要增加跟过的类型
    cfh->ModifyPosition(2,str2);
    cfh->SaveFile("C:\\Users\\Administrator\\Desktop\\ebox-pm-v0.01\\debug\\123\\");
}
