#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QPushButton>

class CheckOut:public QPushButton
{
    Q_OBJECT
public:
    CheckOut(QWidget* qw):QPushButton(qw){};
signals:
    void iChanged(QObject*);
public slots:
    void imClicked(bool);
};

#endif // CHECKOUT_H
