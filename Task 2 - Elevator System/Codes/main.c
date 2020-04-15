#include <REG51F380.H>
#include "lib/std_macros.h"
#include "lib/DIO.h"
#include "lib/LED.h"
#include "lib/button.h"
#include "lib/interrupt.h"
#include <stdio.h>

void delay_ms(int millis);

void main(void)
{ 
	interrupt_vInit();
	interrupt_vEnableExternal(0);
	interrupt_vEnableExternal(1);
	
	// Initialize LED On P1.1 and P2.0
	LED_vInit('1', 0);
	
	// Initialize Button On P3.4
	button_vInit('3', 2);
	button_vInit('3', 3);
	
	while(1)
	{	
		LED_vTurnOff('1', 0);
		delay_ms(50);
	}
}

void EINT_BTN() interrupt 0
{
	LED_vTurnOn('1', 0);
	delay_ms(1000);
}

void EINT_BTN2() interrupt 2
{
	LED_vTurnOn('1', 0);
	delay_ms(3000);
}


void delay_ms(int millis)
{
	unsigned int i, j;
	for(i = 0; i<millis; i++)
	{
		// Wait 1ms
		for(j = 0; j<113; j++);
	}
	
}