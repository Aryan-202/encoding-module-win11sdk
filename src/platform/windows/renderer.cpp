#include <SDL.h>

class WindowRenderer {
public:
    WindowRenderer() : window_(nullptr), renderer_(nullptr), texture_(nullptr) {}

    bool init(int width, int height) {
        SDL_Init(SDL_INIT_VIDEO);
        window_ = SDL_CreateWindow("Media Player", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
        texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_RGB24,
            SDL_TEXTUREACCESS_STREAMING, width, height);
        return true;
    }

    void render(unsigned char* rgbData, int width, int height) {
        SDL_UpdateTexture(texture_, nullptr, rgbData, width * 3);
        SDL_RenderClear(renderer_);
        SDL_RenderCopy(renderer_, texture_, nullptr, nullptr);
        SDL_RenderPresent(renderer_);
    }

private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    SDL_Texture* texture_;
};