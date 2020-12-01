#ifndef DELETEBUTTON_H
#define DELETEBUTTON_H

#include <QPushButton>

class DeleteButton:public QPushButton
{
    Q_OBJECT
public:
    DeleteButton(QWidget* qw):QPushButton(qw){};

signals:
    void iChanged(QObject*);

public slots:
    void imClicked(bool);
};

#endif // DELETEBUTTON_H
