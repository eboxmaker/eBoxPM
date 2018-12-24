#ifndef GLOBALFUNCCLASS_H
#define GLOBALFUNCCLASS_H

/*
 * 用于全局的功能定义和函数接口
 *
 */

#include <QObject>
#include <QTime>
#include <QCoreApplication>

class GlobalFuncClass : public QObject
{
    Q_OBJECT
public:
    explicit GlobalFuncClass(QObject *parent = nullptr);

signals:

public slots:
};

#endif // GLOBALFUNCCLASS_H
