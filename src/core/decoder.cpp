#include "../../include/decoder.h"
#include <iostream>

// Include FFmpeg headers here when ready
// extern "C" {
// #include <libavformat/avformat.h>
// #include <libavcodec/avcodec.h>
// #include <libswscale/swscale.h>
// }

VideoDecoder::VideoDecoder()
    : formatCtx_(nullptr), codecCtx_(nullptr), swsCtx_(nullptr),
    frame_(nullptr), rgbFrame_(nullptr), videoStreamIndex_(-1),
    width_(0), height_(0), eof_(false) {
}

VideoDecoder::~VideoDecoder() {
    close();
}

bool VideoDecoder::open(const std::string& filename) {
    // 1. avformat_open_input
    // 2. avformat_find_stream_info
    // 3. Find video stream
    // 4. avcodec_find_decoder + avcodec_open2
    // 5. Allocate frames
    // 6. Setup sws_scale context for RGB conversion
    std::cout << "Opening video file: " << filename << std::endl;
    return true; // Placeholder
}

void VideoDecoder::close() {
    // Free all FFmpeg resources
}

bool VideoDecoder::readFrame() {
    // 1. av_read_frame
    // 2. avcodec_send_packet / avcodec_receive_frame
    // 3. sws_scale (YUV → RGB)
    return true; // Placeholder
}

unsigned char* VideoDecoder::getCurrentFrameRGB() {
    return nullptr; // Placeholder
}

int VideoDecoder::getWidth() const {
    return width_;
}

int VideoDecoder::getHeight() const {
    return height_;
}