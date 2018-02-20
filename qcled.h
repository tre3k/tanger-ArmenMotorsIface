#ifndef QCLED_H
#define QCLED_H

#include <QWidget>
#include <QQuickWidget>

class QCLed : public QWidget
{
    Q_OBJECT
public:
    explicit QCLed(QWidget *parent = nullptr);

signals:

public slots:

private:
    QQuickWidget *quickWidget;
};

#endif // QCLED_H
