
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

/* Button Pins */
#define BUTTON_1_PIN GPIO_PIN_2 // PB2
#define BUTTON_2_PIN GPIO_PIN_10 // PB10
#define BUTTON_3_PIN GPIO_PIN_11 // PB11
#define BUTTON_4_PIN GPIO_PIN_7 // PA7
#define BUTTON_5_PIN GPIO_PIN_0 // PB0
#define BUTTON_6_PIN GPIO_PIN_1 // PB1