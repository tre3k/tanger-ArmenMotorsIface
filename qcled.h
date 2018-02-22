#ifndef QCLED_H
#define QCLED_H

#include <QWidget>
#include <QQuickWidget>
#include <QVBoxLayout>
#include <QLabel>

class QCLed : public QQuickWidget
{
    Q_OBJECT
public:
    explicit QCLed(QWidget *parent = nullptr);

signals:

public slots:

private:
};

#endif // QCLED_H
