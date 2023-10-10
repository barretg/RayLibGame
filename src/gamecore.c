#include "gamecore.h"
#include "raylib.h"
#include "Gameplay/player.c"
#include "GUI/button.c"

static Player* playerOne;
static Button* startButton;

static enum GAME_PHASE GamePhase = MENU;
static bool close = false;

int main(void)
{
    Init();

    while(!(close |= WindowShouldClose()) && GamePhase == MENU){
        if(UpdateMenu()) {
            GamePhase = STARTING;
        }
        DrawMenu();
    }

    float totalTime = 0.0f;
    while(!(close |= WindowShouldClose()) && GamePhase == STARTING) {
        DrawMenu();
        if ((totalTime += GetFrameTime()) >= 0.1f) {
            GamePhase = PLAYING;
        }
    }

    while (!(close |= WindowShouldClose())) {
        UpdateGame();
        DrawGame();
    }

    DeInit();

    return 0;
}

void Init() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetTargetFPS(FPS);   // Set desired framerate (frames-per-second)

    playerOne = NewPlayer();
    startButton = NewButton();
}

bool UpdateMenu() {
    return UpdateButton(startButton);
}

void DrawMenu() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawButton(startButton);
    EndDrawing();
}

void UpdateGame() {
    float deltaTime = GetFrameTime();

    UpdatePlayer(playerOne, deltaTime);
}

void DrawGame() {
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawPlayer(playerOne);

    EndDrawing();
}

void DeInit() {
    DeletePlayer(playerOne);
    DeleteButton(startButton);
    CloseWindow();
}