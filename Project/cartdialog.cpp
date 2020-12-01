#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cartdialog.h"
#include "ui_cartdialog.h"

#include "pet.h"
#include "bundle.h"
#include "petdatabasesortbyprice.h"
#include "bubblesortincreasing.h"
#include "totalpricevisitor.h"

#include "checkout.h"
#include "deletebutton.h"


#include <sstream>
using std::ostringstream;
#include <iomanip>
using std::fixed;
using std::setprecision;
#include <fstream>
using std::ofstream;

CartDialog::CartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CartDialog)
{
    ui->setupUi(this);
    ui->CartTable->setMinimumWidth(650);
    ui->CartTable->setMaximumWidth(650);
    ui->CartTable->setColumnWidth(0,290);
    ui->CartTable->setColumnWidth(1,290);
    ui->CartTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->CartTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->CartTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->DeleteFromCart,SIGNAL(clicked(bool)),ui->DeleteFromCart,SLOT(imClicked(bool)));
    connect(ui->DeleteFromCart,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->CheckoutButton,SIGNAL(clicked(bool)),ui->CheckoutButton,SLOT(imClicked(bool)));
    connect(ui->CheckoutButton,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));
}

CartDialog::~CartDialog()
{
    delete ui;
}

void CartDialog::actByYourChange(QObject *senderObj){
    if(senderObj==ui->DeleteFromCart){
        int index=ui->CartTable->currentRow();
        if(index!=-1){
            ui->CartTable->removeRow(index);
            MainWindow* parent_ptr=(MainWindow*)parentWidget();
            parent_ptr->m_cart.erase(parent_ptr->m_cart.begin()+index);
        }
    }
    if(senderObj==ui->CheckoutButton){
        MainWindow* parent_ptr=(MainWindow*)parentWidget();
        ui->DeleteFromCart->setEnabled(false);
        parent_ptr->getUI()->AddtoCart->setEnabled(false);
        parent_ptr->getUI()->ShowButton->setEnabled(false);
        PetDataBaseSortByPrice pdbsbp(parent_ptr->m_cart);
        BubbleSortIncreasing bsi;
        bsi.sort(&pdbsbp);
        Bundle checkout_cart("check out",100,parent_ptr->m_cart);
        double price=0;
        for(unsigned int i=0;i<pdbsbp.getSize();i++){
            price+=pdbsbp.getPet(i)->getPrice();
        }
        checkout_cart.setPrice(price);
        string price_str="TOTAL: $"+checkout_cart.displayPrice();
        ui->label->setText(QString::fromStdString(price_str));
        QPalette pal=ui->label->palette();
        pal.setColor(ui->label->foregroundRole(),Qt::red);
        ui->label->setPalette(pal);
        QFont qf=ui->label->font();
        qf.setBold(true);
        ui->label->setFont(qf);
        ofstream outf("Checkout.csv");
        for(unsigned int i=0;i<pdbsbp.getSize();i++){
            outf<<pdbsbp.getPet(i)->getName()<<','<<pdbsbp.getPet(i)->displayPrice()<<'\n';
        }
    }
}

void CartDialog::addIteminTable(std::string name, std::string price){
    int index=ui->CartTable->rowCount();
    ui->CartTable->insertRow(index);
    ui->CartTable->setItem(index,0,new QTableWidgetItem(QString::fromStdString(name)));
    ui->CartTable->setItem(index,1,new QTableWidgetItem(QString::fromStdString(price)));
}

