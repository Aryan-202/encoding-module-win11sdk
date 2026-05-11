#ifndef VIDEO_DECODER_H
#define VIDEO_DECODER_H

#include <string>

// Forward declarations for FFmpeg structs to avoid including headers in this header
struct AVFormatContext;
struct AVCodecContext;
struct AVFrame;
struct SwsContext;

class VideoDecoder {
public:
    VideoDecoder();
    ~VideoDecoder();

    bool open(const std::string& filename);
    void close();
    bool readFrame();

    unsigned char* getCurrentFrameRGB();
    int getWidth() const;
    int getHeight() const;

private:
    AVFormatContext* formatCtx_;
    AVCodecContext* codecCtx_;
    SwsContext* swsCtx_;
    AVFrame* frame_;
    AVFrame* rgbFrame_;
    
    int videoStreamIndex_;
    int width_;
    int height_;
    bool eof_;
};

#endif // VIDEO_DECODER_H