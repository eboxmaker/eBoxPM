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
        fileLineNums = 0;
        QTextStream ts(file);
        while(!ts.atEnd())
        {
            data.append(ts.readLine());
            fileLineNums++;
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
        for(int i = 0; i < fileLineNums; i++)
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
    for(int i = 0; i < fileLineNums; i++)
    {
        if(data[i] == BeginStr)
            indexStart = i;
        if(data[i] == EndStr)
            indexEnd = i;
    }
    for(int i = indexStart + 1; i < indexEnd; i++)
    {
        data[i] = str[i - indexStart - 1];
    }
    if(indexEnd - indexStart - 1== str.count())
        return true;
    else
        return false;
}
