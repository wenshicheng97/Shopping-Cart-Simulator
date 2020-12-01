#ifndef CARTBUTTON_H
#define CARTBUTTON_H

#include <QPushButton>

class CartButton:public QPushButton
{
    Q_OBJECT
public:
    CartButton(QWidget* qw):QPushButton(qw){};
signals:
    void iChanged(QObject*);
public slots:
    void imClicked(bool);
};

#endif // CARTBUTTON_H
