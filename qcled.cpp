#include "qcled.h"

QCLed::QCLed(QWidget *parent) : QQuickWidget(parent)
{
    this->setSource(QUrl("qrc:/led.qml"));
}
