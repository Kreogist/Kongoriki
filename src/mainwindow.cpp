#include "mainwindow.h"
#include <QFileDialog>
#include <QBoxLayout>
#include <QToolButton>
#include <QSlider>

#include <QDebug>

#include "bass/knlibbass.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    bassme=new KNLibBass(this);

    QWidget *w=new QWidget(this);
    setCentralWidget(w);

    QBoxLayout *layout=new QBoxLayout(QBoxLayout::TopToBottom, w);
    w->setLayout(layout);

    QToolButton *b=new QToolButton(this);
    layout->addWidget(b);
    connect(b, SIGNAL(clicked()),
            this, SLOT(onAction()));

    QSlider *s=new QSlider(Qt::Horizontal,this);
    s->setRange(0,10000);
    layout->addWidget(s);
    connect(s, SIGNAL(valueChanged(int)),
            bassme, SLOT(setVolume(int)));

    position=new QSlider(Qt::Horizontal, this);
    layout->addWidget(position);
    connect(bassme, &KNLibBass::positionChanged,
            [=](const quint32 &currPos){
        position->setValue(currPos);
    });
    connect(position, &QSlider::sliderReleased,
            [=]()
    {
        bassme->setPosition(position->value());
    });
//    bassme->loadUrl("http://www.radioparadise.com/musiclinks/rp_128-9.m3u");
    bassme->loadUrl("http://www.xiyufeng.com/bbs/attachment/Type_mp3/16_528_8ae58405ccff512.mp3");
//    bassme->loadUrl("D:/Hans Zimmer - End Credits.mp3");
//    bassme->loadUrl("http://sc.111ttt.com/up/mp3/203516/28BD59C0A62C957D65FECC067D3D2C6A.mp3");
}

void MainWindow::onAction()
{
    QString strData=QFileDialog::getOpenFileName();
    qDebug()<<strData;
    bassme->loadMusic(strData);
    position->setRange(0, bassme->duration());
    bassme->play();
}
