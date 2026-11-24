#include <stdio.h>
#include <map.h>

/*
 *
 *
 */

typedef enum err {
  MALLOC_FAIL,
  OK
} err_t;
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
} power_up_t;

typedef struct tile {
  state_t state;
} tile_t;

typedef struct pos_node {
  position_t pos;
  pos_node *left;
  pos_node *right;
} pos_node_t;

int render() {
  return 0;
}

/*
 * This is for my is in danger tree
 * if a node is in danger a bomb should use insert to add every tile to here
 * so a bomb at (0,0) with radius 2 adds 
 * (0,0), (0,1), (0, 2), (0, -1), (0, -2), (1, 0), (2, 0), (-1, 0), (-2, 0)
 * it shouldn't add if something is inbetween the bomb and the position
 */

int insert(pos_node_t **root, position_t pos) {
  if (*root == NULL) {
    pos_node_t *node = calloc(1, sizeof(pos_node_t));
    if (!node) {
      return MALLOC_FAIL;
    }
    node->pos = pos;
    *root = node;
    return OK;
  }
  if (((*root)->pos.row > pos.row) ||
      (((*root)->pos.row == pos.row) && ((*root)->pos.col > pos.col))) {
    return insert(&((*root)->left), pos);
  }
  else if (((*root)->pos.row < pos.row) ||
           (((*root)->pos.row == pos.row) &&
            ((*root)->pos.col < pos.col))) {
    return insert(&((*root)->right), pos);
  }
  return OK;
} /* insert() */

/*
 *
 */

void tree_free(pos_node_t **root) {
  f (root == NULL) {

  }
  if (*root == NULL) {
    return;
  }
  tree_free(&((*root)->left));
  tree_free(&((*root)->right));
  free(*root);
  *root = NULL;
} /* tree_free() */

/*
 *
 * leetcode 450
 */

pos_node_t *delete_node(pos_node_t **root, positon_t pos) {
  if (root == NULL || *root == NULL ) {
    return NULL;
  }
  pos_node_t *rot = *root;
  if (((*root)->pos.row > pos.row) ||
      (((*root)->pos.row == pos.row) && ((*root)->pos.col > pos.col))) {
    return delete_node(&((*root)->left), pos);
  }
  else if (((*root)->pos.row < pos.row) ||
           (((*root)->pos.row == pos.row) &&
            ((*root)->pos.col < pos.col))) {
    return delete_node(&((*root)->right), pos);
  }
  else {
    //found node to delete
    if (!rot->left) {
      *root = rot->right;
      rot->right = NULL;
      return rot;
    }
    if (!rot->right) {
      *root = rot->left;
      rot->left = NULL;
      return rot;
    }
    pos_node_t *successor = rot->right;
    while (successor->left) {
      successor = successor->left;
    }
    (*root)->pos.row = successor->pos.row;
    (*root)->pos.col = successor->pos.col;
    return delete_node(&((*root)->right), successor->pos);
  }
} /* delete_node() */



