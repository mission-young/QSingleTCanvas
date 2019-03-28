# QSingleTCanvas
QSingleTCanvas is a simplest QtRoot Project, which include TCanvas windows. Unlike other embedded TCanvas, this single TCanvas window keep in step with root TCanvas, which contains all features of latter,such as moving,click,right click,and so on.

Almostly, it's the mininum code, which means every line is necessary. You can develop your QtRoot Project on the basic of it.

- TCanvas windows & main window
![](https://ws1.sinaimg.cn/large/006tKfTcly1g1i89jte8mj30jj0h7t9p.jpg)
- Fit Panel
![](https://ws2.sinaimg.cn/large/006tKfTcly1g1i8aympi3j30tx0hhdij.jpg)
- Editor & Toolbar & ToolTipInfo
![](https://ws2.sinaimg.cn/large/006tKfTcly1g1i8c3lmc3j30p80fxwgh.jpg)

## Code Review
- `main.cpp`
	- `TApplication rootapp("mmDaq Online Monitoring", &argc, argv);`, which is necessary for root-Based GUI app.
	- `rootapp.SetReturnFromRun(true);`,which tell application to return from run. But for now, it seems to be unnecessary?
- `mainwindow.cpp`

```cpp
rootTimer = new QTimer();
connect(rootTimer,SIGNAL(timeout()),this,SLOT(handleRootEvents()));
rootTimer->start(100);
TCanvas *c2=new TCanvas("myCanvas");
TH1D *s=new TH1D("s","s",200,-2,2);
s->Draw();
s->FillRandom("gaus",10000);
c2->Modified();
c2->Update();

void MainWindow::handleRootEvents()
{
  gSystem->ProcessEvents();
}
```
First three lines are used for processing root events every 100ms(`gSystem->ProcessEvents()`). deleting second or third line will response none root event. TCanvas or TH1D must initialize with pointer, otherwises, it will be deleted after constructing of MainWindow.

# Acknowledge
- [meleneemil/OLD-testTCanvasQtMac](https://github.com/meleneemil/OLD-testTCanvasQtMac)