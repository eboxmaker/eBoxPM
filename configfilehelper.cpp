#include "configfilehelper.h"

#include <QCoreApplication>
#include <QDir>
#include <QTextStream>

ConfigFileHelper::ConfigFileHelper()
{

}

bool ConfigFileHelper::LoadFile(QString FileFullPath)
{
    file=new QFile(FileFullPath);
    if(file->open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream ts(file);
        while(!ts.atEnd())
        {
            data.append(ts.readLine());
        }
        QFileInfo *fi = new QFileInfo(FileFullPath);;
        FileName = fi->fileName();
        file->close();
        return true;
    }
    else
    {
        return false;
    }

}
bool ConfigFileHelper::SaveFile(QString Directory)
{
//    QString runPath = QCoreApplication::applicationFilePath();

    QDir *dir = new QDir;
    bool exist = dir->exists(Directory);
    if(!exist)
    {
        dir->mkdir(Directory);
    }
    QString FileFullName = Directory + FileName;
    QFile newFile(FileFullName);

    if (newFile.open(QFile::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&newFile);
        for(int i = 0; i < data.count(); i++)
            out << data[i]<<"\r\n";
        newFile.flush();
        newFile.close();
    }
}
bool ConfigFileHelper::ModifyPosition(int position, QStringList str)
{

    int indexStart;
    int indexEnd;
    QString BeginStr = "//AUTO_CONFIG_CODE_BEGIN_" + QString::number(position, 10);
    QString EndStr = "//AUTO_CONFIG_CODE_END_" + QString::number(position, 10);
    for(int i = 0; i < data.count(); i++)
    {
        if(data[i] == BeginStr)
            indexStart = i;
        if(data[i] == EndStr)
            indexEnd = i;
    }
    for(int i = indexStart + 1; i < indexEnd; i++)
    {
        data.removeAt(indexStart + 1);
    }
    for(int i = 0; i < str.count(); i++)
    {
        data.insert(indexStart + 1,str[str.count() - i - 1]);

    }

    if(indexEnd - indexStart - 1== str.count())
        return true;
    else
        return false;
}
