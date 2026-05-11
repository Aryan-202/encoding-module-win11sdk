#ifndef MEDIA_ENGINE_API_H
#define MEDIA_ENGINE_API_H

#ifdef _WIN32
#ifdef MEDIA_ENGINE_EXPORT
#define MEDIA_API __declspec(dllexport)
#else
#define MEDIA_API __declspec(dllimport)
#endif
#else
#define MEDIA_API __attribute__((visibility("default")))
#endif

typedef struct MediaPlayer MediaPlayer;

// Core lifecycle
MEDIA_API MediaPlayer* media_player_create(void);
MEDIA_API void media_player_destroy(MediaPlayer* player);

// Playback control
MEDIA_API int media_player_play(MediaPlayer* player, const char* filepath);
MEDIA_API void media_player_pause(MediaPlayer* player);
MEDIA_API void media_player_resume(MediaPlayer* player);
MEDIA_API void media_player_stop(MediaPlayer* player);

// Frame access (for UI rendering)
typedef struct {
    unsigned char* data;
    int width;
    int height;
    int linesize;
} VideoFrame;

MEDIA_API VideoFrame* media_player_get_frame(MediaPlayer* player);
MEDIA_API void media_player_free_frame(VideoFrame* frame);

// Status
MEDIA_API int media_player_is_playing(MediaPlayer* player);
MEDIA_API double media_player_get_position(MediaPlayer* player);

#endif