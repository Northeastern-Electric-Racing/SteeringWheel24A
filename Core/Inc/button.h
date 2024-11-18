
#include <stdint.h>
#include <stdbool.h>

typedef enum {
	NERO_BUTTON_LEFT,
	NERO_BUTTON_UP,
	NERO_BUTTON_RIGHT,
	NERO_HOME,
	NERO_BUTTON_SELECT,
	NERO_BUTTON_DOWN,
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
