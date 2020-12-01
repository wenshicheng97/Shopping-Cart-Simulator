#ifndef LOADDATA_H
#define LOADDATA_H
#include <QPushButton>

class LoadData:public QPushButton
{
    Q_OBJECT
public:
    LoadData(QWidget* qw):QPushButton(qw){};
signals:
    void iChanged(QObject*);
public slots:
    void imClicked(bool);
};

#endif // LOADDATA_H
