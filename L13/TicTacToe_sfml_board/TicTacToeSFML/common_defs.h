#ifndef COMMON_DEFS_H
#define COMMON_DEFS_H
#include <vector>
enum class Player { null = 0, cross, circle };
enum class Status { move = 0, win, draw };
using Board = std::vector<std::vector<Player>>;
using Position = std::pair<size_t, size_t>;

#endif // COMMON_DEFS_H
