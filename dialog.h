#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QThread>
#include <QPushButton>
#include <QListWidget>
#include <QVector>

#include <tango.h>
#include <tango/DeviceProxy.h>
#include <tango/AttributeProxy.h>
#include <tango/Connection.h>
#include <tango/DeviceData.h>

using namespace Tango;

struct sMotor{
    DeviceProxy *device;
    QString path;
    QString status;
    bool on;
};

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

    QVector<sMotor> motors;

    void getState();
};

#endif // DIALOG_H
