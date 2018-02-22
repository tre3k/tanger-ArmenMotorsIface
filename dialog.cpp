#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    sMotor motor;

    for(int i=0;i<6;i++){
        motor.path = QString("motors/device/")+QString::number(i);
        motor.device = new DeviceProxy(QString(motor.path).toStdString().c_str());
        motors.append(motor);
        qDebug() << motors.at(i).path << "ping: " << motors.at(i).device->ping() << " s";
    }

    getState();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::getState(){
    QString state;
    for(int i=0;i<motors.size();i++){
        //motors[i].status = QString(motors.at(i).device->status());
        motors[i].status = QString::fromStdString(motors.at(i).device->status());
        if(motors.at(i).device->state()==DevState::ON) motors[i].on=true;
        if(motors.at(i).device->state()==DevState::OFF) motors[i].on=false;
    }

    ui->listWidget->clear();
    for(int i=0;i<motors.size();i++){
        if(motors.at(i).on){
            state = "ON";
        }else{
            state = "OFF";
        }
        ui->listWidget->addItem(motors.at(i).path+" "+motors.at(i).status+" "+state);
    }
}
