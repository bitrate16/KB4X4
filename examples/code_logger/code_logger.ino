#include "KB4X4.h"

// Arduino Pro Micro:
#define R1 2
#define R2 3
#define R3 4
#define R4 5
#define C1 6
#define C2 7
#define C3 8
#define C4 9

KB4X4 keyboard(R1, R2, R3, R4, C1, C2, C3, C4);

void setup() {
	Serial.begin(9600);
}

void loop() {
	int buttonCode = keyboard.getKey();
	if(buttonCode != -1)
		Serial.println(buttonCode);
	delay(100);
}
