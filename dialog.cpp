#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    led1 = new QCLed();
    ui->verticalLayoutLed1->addWidget(led1);

    ArmenMotorsDevice0 = new DeviceProxy("motors/device/0");
    ArmenMotorsDevice1 = new DeviceProxy("motors/device/1");
    ArmenMotorsDevice2 = new DeviceProxy("motors/device/2");
    ArmenMotorsDevice3 = new DeviceProxy("motors/device/3");
    ArmenMotorsDevice4 = new DeviceProxy("motors/device/4");
    ArmenMotorsDevice5 = new DeviceProxy("motors/device/5");
    qDebug () << "Ping: " << ArmenMotorsDevice0->ping();

    /*
    commandList = *(ArmenMotorsDevice0->get_command_list());
    for(int i=0;i<commandList.size();i++){
        qDebug () << QString::fromStdString(commandList.at(i));
    }

    qDebug () << "adm name: " << QString::fromStdString(ArmenMotorsDevice0->adm_name());
    ArmenMotorsDevice0->unlock(false);
    */
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButtonOn_clicked()
{
    qDebug () << "Ping: " << ArmenMotorsDevice0->ping();
    DeviceData arg_in;
    DeviceData arg_out;
    DevBoolean state = true;
    arg_in << state;
    arg_out = ArmenMotorsDevice0->command_inout("PowerOn",arg_in);
    arg_out >> state;
    if(state == true){
        ui->pushButtonOn->setDisabled(true);
        ui->pushButtonOff->setDisabled(false);
    }
}

void Dialog::on_pushButtonOff_clicked()
{
    qDebug () << "Ping: " << ArmenMotorsDevice0->ping();
    DeviceData arg_in;
    DeviceData arg_out;
    DevBoolean state = false;
    arg_in << state;
    ArmenMotorsDevice0->command_inout("Stop");
    arg_out = ArmenMotorsDevice0->command_inout("PowerOn",arg_in);
    arg_out >> state;
    if(state == false){
        ui->pushButtonOn->setDisabled(false);
        ui->pushButtonOff->setDisabled(true);
    }
}

void Dialog::on_pushButtonStop_clicked()
{
    qDebug () << "Ping: " << ArmenMotorsDevice0->ping();
    ArmenMotorsDevice0->command_inout("Stop");
}

void Dialog::on_pushButtonLeft_clicked()
{
    qDebug () << "Ping: " << ArmenMotorsDevice0->ping();
    ArmenMotorsDevice0->command_inout("Stop");
    ArmenMotorsDevice0->command_inout("MotionLeft");

    QTimer::singleShot(1000,this,SLOT(slot_GetEnd()));

}

void Dialog::on_pushButtonRight_clicked()
{
    qDebug () << "Ping: " << ArmenMotorsDevice0->ping();
    ArmenMotorsDevice0->command_inout("Stop");
    ArmenMotorsDevice0->command_inout("MotionRight");
}

void Dialog::slot_GetEnd(){
    qDebug () << "Ping: " << ArmenMotorsDevice0->ping();
    ArmenMotorsDevice0->command_inout("GetEnd");
    
    QTimer::singleShot(1000,this,SLOT(slot_GetEnd()));
}


