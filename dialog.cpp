#include "dialog.h"
#include "ui_dialog.h"

using namespace Tango;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    DeviceProxy *ArmenMotorsDevice = new DeviceProxy("motors/device/0");
    //qDebug () << ArmenMotorsDevice->ping();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButtonOn_clicked()
{

}
