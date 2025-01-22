
#include <stdint.h>
#include <stdbool.h>

typedef enum {
	BUTTON_1,
	BUTTON_2,
	BUTTON_3,
	BUTTON_4,
	BUTTON_5,
	BUTTON_6,
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
