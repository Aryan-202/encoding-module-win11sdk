#ifndef PLAYER_H
#define PLAYER_H

#include "decoder.h"
#include <atomic>
#include <thread>

class MediaPlayer {
public:
    MediaPlayer();
    ~MediaPlayer();

    bool loadFile(const std::string& path);
    void play();
    void pause();
    void stop();

    unsigned char* getCurrentFrame();
    int getFrameWidth() const;
    int getFrameHeight() const;
    bool isPlaying() const { return playing_; }

private:
    void playbackLoop();

    VideoDecoder decoder_;
    std::thread playbackThread_;
    std::atomic<bool> playing_;
    std::atomic<bool> paused_;
    std::atomic<bool> stopRequested_;

    unsigned char* currentFrame_;
    int frameWidth_;
    int frameHeight_;
};

#endif