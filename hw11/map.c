#include <stdio.h>
#include <map.h>

/*
 *
 *
 */

typedef enum state {
  EMPTY,
  BOMB,
  POWERUP,
  DESTRUCTABLE,
  INDESTRUCTABLE,
} state_t;

typedef struct tile {
  state_t state;
} tile_t;


int render() {
  return 0;
}
