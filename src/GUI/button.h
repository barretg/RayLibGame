#include <stdbool.h>

#define DEFAULT_BUTTON_WIDTH 250
#define DEFAULT_BUTTON_HEIGHT (DEFAULT_BUTTON_WIDTH*0.5)

#define DEFAULT_BUTTON_SHAPE (Rectangle) { \
    (SCREEN_WIDTH / 2.0 - DEFAULT_BUTTON_WIDTH/2.0), \
    (SCREEN_HEIGHT / 2.0 - DEFAULT_BUTTON_HEIGHT/2.0), \
    DEFAULT_BUTTON_WIDTH,                  \
    DEFAULT_BUTTON_HEIGHT}

#define DEFAULT_BUTTON_COLOR (Color) LIGHTGRAY
#define DEFAULT_BUTTON_CLICK_COLOR (Color) DARKGRAY

typedef struct button {
    Rectangle shape;
    Color color;
    Color clickColor;
} Button;

Button* NewButton();
void DeleteButton(Button* button);

void DrawButton(Button* button);
bool UpdateButton(Button* button);
