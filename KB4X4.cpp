#include "KB4X4.h"

// R1(C1), R2(C2), R3(C3), R4(C4), C1(R4), C2(R3), C3(R2), C4(R1)
// Changing rows with columns
// Mirror columns
KB4X4::KB4X4(int R1, int R2, int R3, int R4, int C1, int C2, int C3, int C4) : R1(C1), R2(C2), R3(C3), R4(C4), C1(R4), C2(R3), C3(R2), C4(R1) {
	KB4X4:prepare();
}

void KB4X4::prepare() {
	// Write to Rows
	pinMode(R1, INPUT);
	pinMode(R2, INPUT);
	pinMode(R3, INPUT);
	pinMode(R4, INPUT);
	// Read from Columns
	pinMode(C1, INPUT_PULLUP);
	pinMode(C2, INPUT_PULLUP);
	pinMode(C3, INPUT_PULLUP);
	pinMode(C4, INPUT_PULLUP);
}

int KB4X4::getKeys() {	
	int keys = 0;
	
	// R1
	pinMode(R1, OUTPUT);
	digitalWrite(R1, LOW);
	keys |= ((digitalRead(C1) == LOW) << 0 ); // S1
	keys |= ((digitalRead(C2) == LOW) << 1 ); // S2
	keys |= ((digitalRead(C3) == LOW) << 2 ); // S3
	keys |= ((digitalRead(C4) == LOW) << 3 ); // S4
	digitalWrite(R1, HIGH);
	pinMode(R1, INPUT);
	
	// R2
	pinMode(R2, OUTPUT);
	digitalWrite(R2, LOW);
	keys |= ((digitalRead(C1) == LOW) << 4 ); // S1
	keys |= ((digitalRead(C2) == LOW) << 5 ); // S2
	keys |= ((digitalRead(C3) == LOW) << 6 ); // S3
	keys |= ((digitalRead(C4) == LOW) << 7 ); // S4
	digitalWrite(R2, HIGH);
	pinMode(R2, INPUT);
	
	// R3
	pinMode(R3, OUTPUT);
	digitalWrite(R3, LOW);
	keys |= ((digitalRead(C1) == LOW) << 8 ); // S1
	keys |= ((digitalRead(C2) == LOW) << 9 ); // S2
	keys |= ((digitalRead(C3) == LOW) << 10); // S3
	keys |= ((digitalRead(C4) == LOW) << 11); // S4
	digitalWrite(R3, HIGH);
	pinMode(R3, INPUT);
	
	// R4
	pinMode(R4, OUTPUT);
	digitalWrite(R4, LOW);
	keys |= ((digitalRead(C1) == LOW) << 12); // S1
	keys |= ((digitalRead(C2) == LOW) << 13); // S2
	keys |= ((digitalRead(C3) == LOW) << 14); // S3
	keys |= ((digitalRead(C4) == LOW) << 15); // S4
	digitalWrite(R4, HIGH);
	pinMode(R4, INPUT);
	
	return keys;
}

int KB4X4::getKey() {
	int key = -1;
	
	// R1
	pinMode(R1, OUTPUT);
	digitalWrite(R1, LOW);
	if(digitalRead(C1) == LOW)// S1
		key = 0;
	if(digitalRead(C2) == LOW)// S2
		key = 1;
	if(digitalRead(C3) == LOW)// S3
		key = 2;
	if(digitalRead(C4) == LOW)// S4
		key = 3;
	digitalWrite(R1, HIGH);
	pinMode(R1, INPUT);
	if(key != -1)
		return key;
	
	// R2
	pinMode(R2, OUTPUT);
	digitalWrite(R2, LOW);
	if(digitalRead(C1) == LOW)// S1
		key = 4;
	if(digitalRead(C2) == LOW)// S2
		key = 5;
	if(digitalRead(C3) == LOW)// S3
		key = 6;
	if(digitalRead(C4) == LOW)// S4
		key = 7;
	digitalWrite(R2, HIGH);
	pinMode(R2, INPUT);
	if(key != -1)
		return key;
	
	// R3
	pinMode(R3, OUTPUT);
	digitalWrite(R3, LOW);
	if(digitalRead(C1) == LOW)// S1
		key = 8;
	if(digitalRead(C2) == LOW)// S2
		key = 9;
	if(digitalRead(C3) == LOW)// S3
		key = 10;
	if(digitalRead(C4) == LOW)// S4
		key = 11;
	digitalWrite(R3, HIGH);
	pinMode(R3, INPUT);
	if(key != -1)
		return key;
	
	// R4
	pinMode(R4, OUTPUT);
	digitalWrite(R4, LOW);
	if(digitalRead(C1) == LOW)// S1
		key = 12;
	if(digitalRead(C2) == LOW)// S2
		key = 13;
	if(digitalRead(C3) == LOW)// S3
		key = 14;
	if(digitalRead(C4) == LOW)// S4
		key = 15;
	digitalWrite(R4, HIGH);
	pinMode(R4, INPUT);
	if(key != -1)
		return key;
	
	return key;
}