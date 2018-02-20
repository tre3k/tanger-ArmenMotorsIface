#include "qcled.h"

QCLed::QCLed(QWidget *parent) : QWidget(parent)
{
    quickWidget = new QQuickWidget(this);
    quickWidget->setSource(QUrl("QML:/led.qml"));


}
