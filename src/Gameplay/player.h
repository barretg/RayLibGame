#include <stdlib.h>
#include "raylib.h"

#define DEFAULT_PLAYER_SIZE 30
#define DEFAULT_PLAYER_SPEED 400.0f
#define DEFAULT_PLAYER_HEALTH 100.0f
#define DEFAULT_PLAYER_COLOR BLACK

#define DEFAULT_PLAYER_POS (Vector2) { \
    SCREEN_WIDTH / 2.0 - (DEFAULT_PLAYER_SIZE / 2.0), \
    SCREEN_HEIGHT / 2.0 - (DEFAULT_PLAYER_SIZE / 2.0)};

#define DEFAULT_UP (KeyboardKey) KEY_UP
#define DEFAULT_DOWN (KeyboardKey) KEY_DOWN
#define DEFAULT_RIGHT (KeyboardKey) KEY_RIGHT
#define DEFAULT_LEFT (KeyboardKey) KEY_LEFT

typedef struct player_controls {
    KeyboardKey up;
    KeyboardKey down;
    KeyboardKey right;
    KeyboardKey left;
} PlayerControls;

typedef struct player {
    Vector2 pos;
    Color color;
    float health;
    float size;
    float speed;
    PlayerControls* controls;
} Player;

Player* NewPlayer();
void DeletePlayer(Player* player);

void DrawPlayer(Player* player);
void UpdatePlayer(Player* player, float deltaTime);

void Move(Player*, float deltaTime);