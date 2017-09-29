#ifndef KB4X4_H
#define KB4X4_H

#include "Arduino.h"
#import <stdint.h>



// Keyboard 4 x 4 library

// PINOUT:
// \/ Rows ___________________
// R1 --# |S1  |S2  |S3  |S4  |
// R2 --# |____|____|____|____|
// R3 --# |S5  |S6  |S7  |S8  |
// R4 --# |____|____|____|____|
// C1 --# |S9  |S10 |S12 |S13 |
// C2 --# |____|____|____|____|
// C3 --# |S13 |S14 |S15 |S16 |
// C4 --# |____|____|____|____|
// /\ Columns

class KB4X4 {
	private:
		uint16_t R1, R2, R3, R4;
		uint16_t C1, C2, C3, C4;
		void prepare();
		
	public:
		KB4X4(int R1, int R2, int R3, int R4, int C1, int C2, int C3, int C4);
		
		/**
		  * Reads all buttons state and returns integer representing button clicks
		  * Si state = (result >> i) & 1;
		 **/
		int getKeys();
		/**
		  * Reads all buttons state and returns last in Row pressed button
		 **/
		int getKey();
};
#endif