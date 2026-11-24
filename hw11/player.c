#include "map.h"
#include "player.h"
#include


typedef player {
  int row;
  int col;
  power_up_t powers;
  int max_bombs;
  int placed_bombs;
  double speed;
  int shield;
  int phantom;
} player_t;
