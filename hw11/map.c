#include <stdio.h>
#include <map.h>

/*
 *
 *
 */

typedef enum state {
  EMPTY,
  BOMB,
  FIRE,
  POWERUP,
  DESTRUCTABLE,
  INDESTRUCTABLE,
  DANGEROUS,
} state_t;

typedef enum power_up {
  NONE,
  SPEED_UP,
  EXPLOSION_STRENGTH,
  SHIELD,
  BOMB_UP,
  PHANTOM,
} power_up_t

typedef struct tile {
  state_t state;
} tile_t;


int render() {
  return 0;
}
