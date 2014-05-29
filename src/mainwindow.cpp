#include "mainwindow.h"
#include <QFileDialog>

#include "bass/knlibbass.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    KNLibBass *bass=new KNLibBass(this);
    bass->loadMusic(QFileDialog::getOpenFileName());
    bass->play();
}
