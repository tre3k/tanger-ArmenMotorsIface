#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ArmenMotorsDevice = new DeviceProxy("motors/device/0");

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButtonOn_clicked()
{
    qDebug () << ArmenMotorsDevice->ping();
}
