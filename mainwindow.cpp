#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    rootTimer = new QTimer();
    connect(rootTimer,SIGNAL(timeout()),this,SLOT(handleRootEvents()));
    rootTimer->start(100);
    TCanvas *c2=new TCanvas("myCanvas");
    TH1D *s=new TH1D("s","s",200,-2,2);
    s->Draw();
    s->FillRandom("gaus",10000);

    c2->Modified();
    c2->Update();

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::handleRootEvents()
{
  gSystem->ProcessEvents();
}
