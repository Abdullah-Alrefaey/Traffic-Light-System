#include "delay.h"

void delay_ms(int millis)
{
	unsigned int i, j;
	for(i = 0; i<millis; i++)
	{
		// Wait 1ms
		for(j = 0; j<113; j++);
	}
}