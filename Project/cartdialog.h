#ifndef CARTDIALOG_H
#define CARTDIALOG_H

#include <QDialog>
#include <QPalette>

#include <string>
using std::string;

namespace Ui {
class CartDialog;
}

class CartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CartDialog(QWidget *parent = 0);
    ~CartDialog();

    Ui::CartDialog* getUI(){return ui;}

    void addIteminTable(string name, string price);

public slots:
    void actByYourChange(QObject*);

private:
    Ui::CartDialog *ui;
};

#endif // CARTDIALOG_H
