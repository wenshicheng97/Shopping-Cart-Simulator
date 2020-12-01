#ifndef ADDBUTTON_H
#define ADDBUTTON_H
#include <QPushButton>

class AddButton:public QPushButton
{
    Q_OBJECT
public:
    AddButton(QWidget* qw):QPushButton(qw){};
signals:
    void iChanged(QObject*);
public slots:
    void ItemAdded(bool);
};

#endif // ADDBUTTON_H
