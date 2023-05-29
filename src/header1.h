// We define various Delays that we might need to use

#define DELAY1 10000
#define DELAY2 20000
#define DELAY3 5000
#define DELAY4 3000
#define DELAY5 1500
#define DELAY6 15000
#define ON 0x01
#define OFF 0x00
#define NUM_LEDS 0x03

// RGB lights (We do not use them here but we use them in LAB 4)
#define RED_LED 0x00400000
#define BLUE_LED 0x00200000
#define GREEN_LED 0x00080000

// Traffic lights at intersection 1
#define NS_RED 0x00040000
#define NS_YELLOW 0x00800000
#define NS_GREEN 0x00000001

// Traffic lights at intersection 2
#define EW_RED 0x00000002
#define EW_YELLOW 0x00000800
#define EW_GREEN 0x00001000

// Pedestrian lights green and red
#define PED_GREEN 0x00100000
#define PED_RED 0x00000004

// Push button
#define PB1 0x00002000

void setupGPIO();
int setLED(int color, int state);
void delay(int milliseconds);
int checkBot(int pin);