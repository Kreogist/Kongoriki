#ifndef KNLIBBASS_H
#define KNLIBBASS_H

#include <stdio.h>
#include "bass.h"

#include <QObject>

class KNLibBass : public QObject
{
    Q_OBJECT
public:
    explicit KNLibBass(QObject *parent = 0);
    ~KNLibBass();
    void loadMusic(const QString &filePath);
    void play();

signals:

public slots:

private:
    DWORD m_channel, m_floatable;
};

#endif // KNLIBBASS_H
