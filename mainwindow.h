#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <TCanvas.h>
#include <TVirtualX.h>
#include <TSystem.h>
#include <TStyle.h>
#include <TFormula.h>
#include <TF1.h>
#include <TH1.h>
#include <TFrame.h>
#include <TTimer.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void handleRootEvents();


    void on_le_cmd_returnPressed();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    TCanvas* c1;
    TH1D* h;
    QTimer* rootTimer;
};

#endif // MAINWINDOW_H
