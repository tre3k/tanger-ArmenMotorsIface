#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>

#include <tango.h>
#include <tango/DeviceProxy.h>

using namespace Tango;

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
    void on_pushButtonOn_clicked();

private:
    DeviceProxy *ArmenMotorsDevice;

    Ui::Dialog *ui;
};

#endif // DIALOG_H
