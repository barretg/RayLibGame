#include "player.h"

Player* NewPlayer() {
    Player *newPlayer;
    newPlayer = malloc(sizeof(Player));

    // Set all values to default
    newPlayer->pos = DEFAULT_PLAYER_POS;
    newPlayer->color = DEFAULT_PLAYER_COLOR;
    newPlayer->health = DEFAULT_PLAYER_HEALTH;
    newPlayer->speed = DEFAULT_PLAYER_SPEED;
    newPlayer->size = DEFAULT_PLAYER_SIZE;

    //Set player controls to default
    PlayerControls* controls;
    controls = malloc(sizeof(PlayerControls));
    controls->up = DEFAULT_UP;
    controls->down = DEFAULT_DOWN;
    controls->right = DEFAULT_RIGHT;
    controls->left = DEFAULT_LEFT;
    newPlayer->controls = controls;

    return newPlayer;
}

void DrawPlayer(Player* player) {
    DrawRectangleV(player->pos, (Vector2) {player->size, player->size}, player->color);
}

void UpdatePlayer(Player* player, float deltaTime) {
    Move(player, deltaTime);
}

void Move(Player* player, float deltaTime) {
    PlayerControls* controls = player->controls;

    float distance = player->speed * deltaTime;

    if (IsKeyDown(controls->up)) player->pos.y -= distance;
    if (IsKeyDown(controls->down)) player->pos.y += distance;
    if (IsKeyDown(controls->left)) player->pos.x -= distance;
    if (IsKeyDown(controls->right)) player->pos.x += distance;
}

void DeletePlayer(Player* player) {
    PlayerControls* controls = player->controls;
    free(controls);
    free(player);
}
