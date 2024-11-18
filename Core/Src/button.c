
#include "button.h"
#include <stdlib.h>

button_t buttons[MAX_BUTTON_SIZE];

void init_buttons()
{
	button_t *nero_left = malloc(sizeof(button_t));
	nero_left->button_id = 1;
	buttons[NERO_BUTTON_LEFT] = *nero_left;

	button_t *nero_right = malloc(sizeof(button_t));
	nero_left->button_id = 2;
	buttons[NERO_BUTTON_RIGHT] = *nero_right;

	button_t *nero_up = malloc(sizeof(button_t));
	nero_left->button_id = 4;
	buttons[NERO_BUTTON_UP] = *nero_up;

	button_t *nero_down = malloc(sizeof(button_t));
	nero_left->button_id = 8;
	buttons[NERO_BUTTON_DOWN] = *nero_down;

	button_t *nero_select = malloc(sizeof(button_t));
	nero_left->button_id = 16;
	buttons[NERO_BUTTON_SELECT] = *nero_select;

	button_t *nero_home = malloc(sizeof(button_t));
	nero_left->button_id = 32;
	buttons[NERO_HOME] = *nero_home;
}