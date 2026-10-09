/*
	Filename: fir.cpp
		FIR lab wirtten for WES/CSE237C class at UCSD.
		Match filter
	INPUT:
		x: signal (chirp)

	OUTPUT:
		y: filtered output

*/

#include "fir.h"
void fir (
  data_t *y,
  data_t x
  )
{
	//N = 128
	//bit needed to represent 11 is 5, 1 sign bit and 4 base bits 
	coef_t c[N] = {10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	
	// Write your code here
	static data_t shift_reg[N]; //static array for sample persistence
	acc_t acc = 0; //accumulaor

	//shift loop
	for(int i = N-1; i >= 0; i--) //loop bakcwards
	{
		#pragma HLS pipeline off
		//pragma HLS pipeline II = 5
		if(i){ //if not index zero
		shift_reg[i] = shift_reg[i-1];
		acc += shift_reg[i] * c[i];
		}

		else //is 0
		{shift_reg[0] = x; //
			acc += x * c[0];
		}

	}

	*y = (data_t)acc;
}

