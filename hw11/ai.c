#include <stdio.h>
#include "ai.h"
#include 


typedef enum {
  WANDER,
  FLEE,
  ATTACK,
  GREEDY
} AIstate;

typedef struct {
  int row;
  int col;
} Position;

typedef struct {
  AIstate state;
  Position pos;
  int num_bombs;
} Bot_t;


