#include "../include/decoder.h"
#include <cassert>
#include <iostream>

int main() {
    VideoDecoder decoder;

    // Test opening a real video file
    bool opened = decoder.open("test.mp4");
    assert(opened);

    // Test reading frames
    bool hasFrame = decoder.readFrame();
    assert(hasFrame);

    // Test getting RGB data
    unsigned char* rgb = decoder.getCurrentFrameRGB();
    assert(rgb != nullptr);
    assert(decoder.getWidth() > 0);
    assert(decoder.getHeight() > 0);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}