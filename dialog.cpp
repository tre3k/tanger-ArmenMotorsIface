#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ArmenMotorsDevice = new DeviceProxy("motors/device/0");
    qDebug () << "Ping: " << ArmenMotorsDevice->ping();

    commandList = *(ArmenMotorsDevice->get_command_list());
    for(int i=0;i<commandList.size();i++){
        qDebug () << QString::fromStdString(commandList.at(i));
    }

    qDebug () << "Adm: " << QString::fromStdString(ArmenMotorsDevice->adm_name());

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButtonOn_clicked()
{
    qDebug () << "Ping: " << ArmenMotorsDevice->ping();

}

void Dialog::on_pushButtonOff_clicked()
{

}

void Dialog::on_pushButtonStop_clicked()
{
    qDebug () << "Ping: " << ArmenMotorsDevice->ping();
    ArmenMotorsDevice->command_query("Stop");
}

void Dialog::on_pushButtonLeft_clicked()
{
    qDebug () << "Ping: " << ArmenMotorsDevice->ping();
    ArmenMotorsDevice->command_query("Stop");
    ArmenMotorsDevice->command_query("MotionLeft");
}

void Dialog::on_pushButtonRight_clicked()
{
    qDebug () << "Ping: " << ArmenMotorsDevice->ping();
    ArmenMotorsDevice->command_query((string)"Stop");
    ArmenMotorsDevice->command_query((string)"MotionRight");
}


