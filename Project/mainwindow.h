#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "cartdialog.h"
#include "pet.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    CartDialog* cartwindow=new CartDialog(this);
    std::vector<Pet*> m_cart;

    Ui::MainWindow* getUI() const{return ui;}

public slots:
    void actByYourChange(QObject*);

private:
    Ui::MainWindow *ui;

protected:
    std::vector<Pet*> m_petlist;
    std::vector<Pet*> m_bundlelist;
    int showbuttonclickedtime=0;
};

#endif // MAINWINDOW_H
