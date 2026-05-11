#include "media_engine/api.h"
#include "../core/player.h"
#include <unordered_map>

static std::unordered_map<MediaPlayer*, std::unique_ptr<MediaPlayer>> g_players;

MEDIA_API MediaPlayer* media_player_create() {
    auto player = new MediaPlayer();
    g_players[player] = std::unique_ptr<MediaPlayer>(player);
    return player;
}

MEDIA_API void media_player_destroy(MediaPlayer* player) {
    g_players.erase(player);
}

MEDIA_API int media_player_play(MediaPlayer* player, const char* filepath) {
    if (!player->loadFile(filepath)) return -1;
    player->play();
    return 0;
}

MEDIA_API VideoFrame* media_player_get_frame(MediaPlayer* player) {
    auto* frame = new VideoFrame();
    frame->data = player->getCurrentFrame();
    frame->width = player->getFrameWidth();
    frame->height = player->getFrameHeight();
    frame->linesize = frame->width * 3;
    return frame;
}