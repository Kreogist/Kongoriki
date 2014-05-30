#include "mainwindow.h"
#include <QFileDialog>
#include <QBoxLayout>
#include <QToolButton>
#include <QSlider>

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
}

void MainWindow::onAction()
{
    bassme->loadMusic(QFileDialog::getOpenFileName());
    position->setRange(0, bassme->duration());
    bassme->play();
}
