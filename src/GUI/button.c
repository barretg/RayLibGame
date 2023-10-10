#include "button.h"

bool pressed = false;

Button* NewButton() {
    Button* newButton = malloc(sizeof(Button));

    newButton->shape = DEFAULT_BUTTON_SHAPE;
    newButton->color = DEFAULT_BUTTON_COLOR;
    newButton->clickColor = DEFAULT_BUTTON_CLICK_COLOR;

    return newButton;
}

void DeleteButton(Button* button) {
    free(button);
}

void DrawButton(Button* button){
    if (pressed) {
        DrawRectangleRec(button->shape, button->clickColor);
    } else {
        DrawRectangleRec(button->shape, button->color);
    }
}

bool UpdateButton(Button* button){
    Vector2 mousePos = GetMousePosition();

    if(CheckCollisionPointRec(mousePos, button->shape) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        pressed = true;

    return pressed;
}