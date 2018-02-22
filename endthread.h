#ifndef ENDTHREAD_H
#define ENDTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>

#include <tango.h>
#include <tango/DeviceProxy.h>

using namespace Tango;

class EndThread : public QThread
{
    Q_OBJECT
public:
    explicit EndThread(DeviceProxy *devProxy);

    void run();

signals:
    void signal_end(bool);
public slots:
private:
    DeviceProxy *device;
};

#endif // ENDTHREAD_H
