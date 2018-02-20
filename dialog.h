#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include <QTimer>

#include <tango.h>
#include <tango/DeviceProxy.h>
#include <tango/AttributeProxy.h>
#include <tango/Connection.h>
#include <tango/DeviceData.h>

#include "qcled.h"

using namespace Tango;
using namespace std;

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
    void slot_GetEnd();

    void on_pushButtonOn_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonLeft_clicked();

    void on_pushButtonRight_clicked();

    void on_pushButtonOff_clicked();

private:
    DeviceProxy *ArmenMotorsDevice0;
    DeviceProxy *ArmenMotorsDevice1;
    DeviceProxy *ArmenMotorsDevice2;
    DeviceProxy *ArmenMotorsDevice3;
    DeviceProxy *ArmenMotorsDevice4;
    DeviceProxy *ArmenMotorsDevice5;

    QCLed *led1;


    vector<string> commandList;

    Ui::Dialog *ui;
};

#endif // DIALOG_H
