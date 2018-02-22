#include "endthread.h"

EndThread::EndThread(DeviceProxy *devProxy) : device(devProxy)
{

}

void EndThread::run(){
    DeviceData arg_out;
    DevBoolean devState;

    while(1){
        QThread::msleep(1000);
        qDebug () << device->ping();

        arg_out = device->command_inout("GetEnd");
        arg_out >> devState;

        emit signal_end(devState);
    }
}
