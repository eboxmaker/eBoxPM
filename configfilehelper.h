#ifndef CONFIGFILEHELPER_H
#define CONFIGFILEHELPER_H

#include <QFile>
#include <QString>



class ConfigFileHelper
{
public:
    ConfigFileHelper();
    bool LoadFile(QString FileFullPath);
    bool SaveFile(QString Directory);
    bool ModifyPosition(int position,QStringList str);
public:
    QString FileName;
    QFile   *file;
    QStringList data;
};

#endif // CONFIGFILEHELPER_H
