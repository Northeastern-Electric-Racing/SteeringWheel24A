
#include "button.h"
#include <stdlib.h>

button_t buttons[MAX_BUTTON_SIZE];

void init_buttons()
{
	button_t *button_left = malloc(sizeof(button_t));
	button_left->button_id = 0;
	buttons[BUTTON_LEFT] = *button_left;

	button_t *button_right = malloc(sizeof(button_t));
	button_right->button_id = 1;
	buttons[BUTTON_RIGHT] = *button_right;

	button_t *button_esc = malloc(sizeof(button_t));
	button_esc->button_id = 2;
	buttons[BUTTON_ESC] = *button_esc;

	button_t *button_up = malloc(sizeof(button_t));
	button_up->button_id = 3;
	buttons[BUTTON_UP] = *button_up;

	button_t *button_down = malloc(sizeof(button_t));
	button_down->button_id = 4;
	buttons[BUTTON_DOWN] = *button_down;

	button_t *button_enter = malloc(sizeof(button_t));
	button_enter->button_id = 5;
	buttons[BUTTON_ENTER] = *button_enter;
}