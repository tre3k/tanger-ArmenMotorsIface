#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include <QListWidget>
#include <QVector>
#include <QLabel>
#include <QCheckBox>

#include <tango.h>
#include <tango/DeviceProxy.h>
#include <tango/AttributeProxy.h>
#include <tango/Connection.h>
#include <tango/DeviceData.h>

#include "endthread.h"

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

private slots:
    void slot_End(bool);

    void on_pushButton_On_clicked();

    void on_pushButton_Off_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_left_clicked();



private:
    Ui::Dialog *ui;

    QVector<sMotor> motors;
    EndThread *eThread;

    void getState();
};

#endif // DIALOG_H
