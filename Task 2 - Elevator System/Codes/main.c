#include <REG51F380.H>
#include "lib/delay.h"
#include "lib/std_macros.h"
#include "lib/DIO.h"
#include "lib/LED.h"
#include "lib/button.h"
#include "lib/interrupt.h"
#include "lib/stepperMotor.h"
#include <stdio.h>

unsigned char persons = 0;			// Number of persons
unsigned char i_warn;				// Warning counter in the loop
unsigned char doorOpenStatus = 1;	// Initially the door is opened
unsigned char currentFloor = 0;		// Current Floor of the Elevator
unsigned char floor0Btn, floor1Btn, floor2Btn, floor3Btn, floor4Btn;
int main()
{	
	// Initialization of stepper motor and external interrupts
	stepper_vInit();
	interrupt_vInit();
	interrupt_vEnableExternal(0);
	interrupt_vEnableExternal(1);
	
	// Initialize the warning LED of maximum persons
	LED_vInit('3', 7);
	LED_vTurnOff('3', 7);
	
	// Initialize interrupts Buttons
	button_vInit('3', 2);
	button_vInit('3', 3);
	
	// Initialize Elevator Buttons
	button_vInit('0', 0);
	button_vInit('0', 1);
	button_vInit('0', 2);
	button_vInit('0', 3);
	button_vInit('0', 4);
	
	while(1)
	{	
		floor0Btn = button_u8read('0', 0);
		floor1Btn = button_u8read('0', 1);
		floor2Btn = button_u8read('0', 2);
		floor3Btn = button_u8read('0', 3);
		floor4Btn = button_u8read('0', 4);
		
		if(floor4Btn == 0)
		{
			// Wait 5 seconds to close the door
			delay_ms(5000);
			LED_vTurnOn('3', 7);
			stepper_vUp();
			delay_ms(10);
			currentFloor = 4;
		}
		
		if(floor0Btn == 0)
		{
			LED_vTurnOff('3', 7);
			stepper_vDown();
			delay_ms(10);
			currentFloor = 0;
		}
	}
}


void openTheDoor() interrupt 0
{
	/*
		INT0 ISR:
		Prevent the door from closing 
		Or to Force the door to be opened
	*/
	doorOpenStatus = 1;
	
	// Code here
	
	delay_ms(1);
}

void personIn() interrupt 2
{
	/*
		INT1 ISR:
		Add one person in each Buttn Click
	*/
	
	if(persons < 4)
	{
		persons += 1;
	}
	else
	{
		// Warning Maximum Persons		
		for(i_warn=0; i_warn<100; i_warn++)
		{
			LED_vToggle('3', 7);
			delay_ms(10);
		}
		LED_vTurnOff('3', 7);
	}
}
