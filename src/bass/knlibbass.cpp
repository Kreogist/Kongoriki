#include <QDebug>

#include "knlibbass.h"

KNLibBass::KNLibBass(QObject *parent) :
    QObject(parent)
{
    //Check bass version.
    if(HIWORD(BASS_GetVersion())!=BASSVERSION)
    {
        qDebug()<<"Bass version error!";
    }
    //Set Configure, I don't know what's this use.
    BASS_SetConfig(BASS_CONFIG_FLOATDSP,TRUE);
    if(!BASS_Init(-1,44100,0,NULL,NULL))
    {
        qDebug()<<"Cannot init bass library.";
        return;
    }
    //Check floatable.
    m_floatable=BASS_StreamCreate(44100,2,BASS_SAMPLE_FLOAT,NULL,0);
    if(m_floatable)
    {
        //Support floatable
        BASS_StreamFree(m_floatable);
        m_floatable=BASS_SAMPLE_FLOAT;
    }
}

KNLibBass::~KNLibBass()
{
    BASS_Free();
}

void KNLibBass::loadMusic(const QString &filePath)
{
    BASS_MusicFree(m_channel);
    BASS_StreamFree(m_channel);
    if(!(m_channel=BASS_StreamCreateFile(FALSE,filePath.toLocal8Bit().data(),0,0,BASS_SAMPLE_LOOP|m_floatable))
            && !(m_channel=BASS_MusicLoad(FALSE,filePath.toLocal8Bit().data(),0,0,BASS_SAMPLE_LOOP|BASS_MUSIC_RAMPS|m_floatable,1)))
    {
        qDebug()<<"Can't play the file";
    }
}

void KNLibBass::play()
{
    BASS_ChannelPlay(m_channel, FALSE);
}
