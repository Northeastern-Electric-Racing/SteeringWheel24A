
#include <stdint.h>
#include <stdbool.h>

typedef enum {
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_ESC,
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_ENTER,
	MAX_BUTTON_SIZE,
} steeringio_button_t;

typedef struct button {
	uint8_t button_id;
	uint32_t prev_tick;
	bool pressed;
} button_t;

/**
 * @brief initializes all buttons on steering wheel
 */
void init_buttons();
