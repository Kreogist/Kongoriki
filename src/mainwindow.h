#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QSlider;
class KNLibBass;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:
    void onAction();

private:
    KNLibBass *bassme;
    QSlider *position;
};

#endif // MAINWINDOW_H
