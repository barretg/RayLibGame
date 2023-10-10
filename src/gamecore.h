#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define GAME_NAME "Raylib 2D Game"
#define FPS 60

enum GAME_PHASE {
    MENU,
    STARTING,
    PLAYING,
};

void Init();

bool UpdateMenu();
void DrawMenu();

void UpdateGame();
void DrawGame();

void DeInit();