
#include "button.h"
#include <stdlib.h>

button_t buttons[MAX_BUTTON_SIZE];

void init_buttons()
{
	button_t *nero_left = malloc(sizeof(button_t));
	nero_left->button_id = 0;
	buttons[BUTTON_1] = *nero_left;

	button_t *nero_right = malloc(sizeof(button_t));
	nero_left->button_id = 1;
	buttons[BUTTON_2] = *nero_right;

	button_t *nero_up = malloc(sizeof(button_t));
	nero_left->button_id = 2;
	buttons[BUTTON_3] = *nero_up;

	button_t *nero_down = malloc(sizeof(button_t));
	nero_left->button_id = 3;
	buttons[BUTTON_4] = *nero_down;

	button_t *nero_select = malloc(sizeof(button_t));
	nero_left->button_id = 4;
	buttons[BUTTON_5] = *nero_select;

	button_t *nero_home = malloc(sizeof(button_t));
	nero_left->button_id = 5;
	buttons[BUTTON_6] = *nero_home;
}