#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loaddata.h"
#include "addbutton.h"

#include "pet.h"
#include "builder.h"
#include "petlistbuilder.h"
#include "petlistparser.h"
#include "bundlelistparser.h"
#include "petdatabasesearchablesortbyname.h"
#include "bubblesortincreasing.h"

/*
#include <iomanip>
#include <iostream>
using std::cout;
using std::endl;
using std::boolalpha;*/
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::to_string;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Pet Database");
    //this->setMinimumHeight(600);
    this->setMaximumWidth(870);
    ui->ItemTable->setMinimumWidth(750);
    ui->ItemTable->setMaximumWidth(750);
    //ui->ItemTable->setRowCount(0);
    ui->ItemTable->setColumnCount(4);
    ui->ItemTable->setColumnWidth(0,125);
    ui->ItemTable->setColumnWidth(1,125);
    ui->ItemTable->setColumnWidth(2,125);
    ui->ItemTable->setColumnWidth(3,300);
    ui->ItemTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ItemTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->ItemTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->BundleTable->setMinimumWidth(750);
    ui->BundleTable->setMaximumWidth(750);
    ui->BundleTable->setRowCount(0);
    ui->BundleTable->setColumnCount(3);
    ui->BundleTable->setColumnWidth(0,400);
    ui->BundleTable->setColumnWidth(1,140);
    ui->BundleTable->setColumnWidth(2,140);
    ui->BundleTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->BundleTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->BundleTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->AddtoCart->setEnabled(false);
    ui->ShowButton->setEnabled(false);

    connect(ui->LoadButton,SIGNAL(clicked(bool)),ui->LoadButton,SLOT(imClicked(bool)));
    connect(ui->LoadButton,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->AddtoCart,SIGNAL(clicked(bool)),ui->AddtoCart,SLOT(ItemAdded(bool)));
    connect(ui->AddtoCart,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->ShowButton,SIGNAL(clicked(bool)),ui->ShowButton,SLOT(imClicked(bool)));
    connect(ui->ShowButton,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actByYourChange(QObject *senderObj){
    if(senderObj==ui->LoadButton){
        ui->LoadButton->setEnabled(false);
        ui->AddtoCart->setEnabled(true);
        ui->ShowButton->setEnabled(true);
        PetListBuilder builder1;
        PetListParser parser1;
        parser1.setBuilder(&builder1);
        parser1.parse();
        vector<Pet*> petlist=builder1.getList();
        PetDataBaseSearchableSortByName pdssbn(petlist);
        BubbleSortIncreasing bsi;
        bsi.sort(&pdssbn);
        int sz=pdssbn.getSize();
        for(int i=0;i<sz;i++){
            Pet* p=pdssbn.getPet(i);
            m_petlist.push_back(p);
            ui->ItemTable->insertRow(ui->ItemTable->rowCount());
            ui->ItemTable->setItem(i,0,new QTableWidgetItem(QString::fromStdString(p->getName())));
            ui->ItemTable->setItem(i,1,new QTableWidgetItem(QString::fromStdString(p->getClass())));
            ui->ItemTable->setItem(i,2,new QTableWidgetItem(QString::fromStdString(p->displayPrice())));
            ui->ItemTable->setItem(i,3,new QTableWidgetItem(QString::fromStdString(p->getSpecial())));
        }
        //BundleListBuilder builder2;
        PetListBuilder builder2;
        BundleListParser parser2;
        parser2.setBuilder(&builder2);
        parser2.parse(&pdssbn);
        vector<Pet*> bundlelist=builder2.getList();
        PetDataBaseSearchableSortByName pdbssbn2(bundlelist);
        BubbleSortIncreasing bsi2;
        bsi2.sort(&pdbssbn2);
        int sz2=pdbssbn2.getSize();
        for(int i=0;i<sz2;i++){
            Pet* p=pdbssbn2.getPet(i);
            m_bundlelist.push_back(p);
            ui->BundleTable->insertRow(ui->BundleTable->rowCount());
            ui->BundleTable->setItem(i,0,new QTableWidgetItem(QString::fromStdString(p->getName())));
            ui->BundleTable->setItem(i,1,new QTableWidgetItem(QString::fromStdString(p->displayPrice())));
            ui->BundleTable->setItem(i,2,new QTableWidgetItem(QString::fromStdString(p->getSpecial())));
        }
    }
    if(senderObj==ui->ShowButton){
        if(showbuttonclickedtime%2==0){
            cartwindow->show();
            ui->ShowButton->setText("Hide Cart");
        }
        else{
            cartwindow->close();
            ui->ShowButton->setText("Show Cart");
        }
        showbuttonclickedtime++;

    }
    if(senderObj==ui->AddtoCart){
        int index1=ui->ItemTable->currentRow();
        int index2=ui->BundleTable->currentRow();
        if(index1!=-1){
            Pet* item=m_petlist[index1];
            m_cart.push_back(item);
            cartwindow->addIteminTable(item->getName(),item->displayPrice());
        }
        if(index2!=-1){
            Pet* bundle=m_bundlelist[index2];
            m_cart.push_back(bundle);
            cartwindow->addIteminTable(bundle->getName(),bundle->displayPrice());
        }
        ui->ItemTable->setCurrentCell(-1,-1);
        ui->BundleTable->setCurrentCell(-1,-1);
    }
}

