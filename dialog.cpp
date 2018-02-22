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

    eThread = new EndThread(motors.at(0).device);
    eThread->start();

    connect(eThread,SIGNAL(signal_end(bool)),
            this,SLOT(slot_End(bool)));

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
        if(motors.at(i).on){
            ui->listWidget->item(i)->setBackground(QBrush("green"));
        }
    }
}

void Dialog::on_pushButton_On_clicked()
{
    qDebug () << "Ping: " << motors.at(0).device->ping();
    DeviceData arg_in;
    DeviceData arg_out;
    DevBoolean state = true;
    arg_in << state;

    for(int i=0;i<ui->listWidget->count();i++){
        if(ui->listWidget->item(i)->isSelected()){
            arg_out = motors.at(i).device->command_inout("PowerOn",arg_in);
            arg_out >> state;
            if(!state) qDebug() << "motor " << QString::number(i) << " not on!\n";
        }
    }

    getState();


}

void Dialog::on_pushButton_Off_clicked()
{
    qDebug () << "Ping: " << motors.at(0).device->ping();
    DeviceData arg_in;
    DeviceData arg_out;
    DevBoolean state = false;
    arg_in << state;

    for(int i=0;i<ui->listWidget->count();i++){
        if(ui->listWidget->item(i)->isSelected()){
            arg_out = motors.at(i).device->command_inout("PowerOn",arg_in);
            arg_out >> state;
            if(state) qDebug() << "motor " << QString::number(i) << " not off!\n";
        }
    }

    getState();
}

void Dialog::on_pushButton_stop_clicked()
{
    for(int i=0;i<ui->listWidget->count();i++){
        if(ui->listWidget->item(i)->isSelected()){
            motors.at(i).device->command_inout("Stop");
        }
    }
    getState();
}

void Dialog::on_pushButton_right_clicked()
{
    for(int i=0;i<ui->listWidget->count();i++){
        if(ui->listWidget->item(i)->isSelected()){
            motors.at(i).device->command_inout("Stop");
            motors.at(i).device->command_inout("MotionRight");
        }
    }
    getState();
}

void Dialog::on_pushButton_left_clicked()
{
    for(int i=0;i<ui->listWidget->count();i++){
        if(ui->listWidget->item(i)->isSelected()){
            motors.at(i).device->command_inout("Stop");
            motors.at(i).device->command_inout("MotionLeft");
        }
    }
    getState();
}

void Dialog::slot_End(bool state){
    if(state){
        ui->labelEnd->setText("END");
        if(ui->checkBox->isChecked()) on_pushButton_stop_clicked();
    }else{
        ui->labelEnd->setText(" ");
    }
}
