//
//  SongManager.h
//  heinneken
//
//  Created by miguel on 04/11/14.
//
//

#ifndef __heinneken__SongManager__
#define __heinneken__SongManager__

#include "ofMain.h"

class SongManager
{
    
public:
    SongManager();
    ~SongManager();
    
    int song = 0;
    bool bPlaying = false;
    
    void playSong();
    void stopSong();
    void togglePlay();
    void playNextSong();
    void prevSong();
    void setMidiAndNext();
    string toString();
    string help();
};


#endif /* defined(__heinneken__SongManager__) */
