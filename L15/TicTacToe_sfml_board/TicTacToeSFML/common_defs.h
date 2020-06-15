#ifndef COMMON_DEFS_H
#define COMMON_DEFS_H
#include <vector>
enum class Player { null = 0, cross, circle };
enum class Status { move = 0, win, draw };
using Board = std::vector<std::vector<Player>>;
using Position = std::pair<size_t, size_t>;

enum class Request { status, move, active_player, is_finished, restart };
struct ComFrame
{
    Request request;
    Player player;
    Status status;
    Position position;
    Player board[9];
};

#endif // COMMON_DEFS_H
