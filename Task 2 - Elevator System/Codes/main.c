#include <REGX51.H>
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
unsigned int floor0Btn, floor1Btn, floor2Btn, floor3Btn, floor4Btn;
unsigned int Up[5] = {1, 1, 1, 1, 1};
unsigned int Down[5] = {1, 1, 1, 1, 1};
unsigned int Floors[5] = {1, 1, 1, 1, 1};
int  Direction = 1; //Up is True, Down is False
int i, temp, temp2;
int stopped = 0;
int CheckUp(unsigned int floorDir[5], unsigned int floorNumber), CheckDown(unsigned int floorDir[5], unsigned int floorNumber);
int CheckButtonIn(int CurrentFloor);
int CheckButtonOut(int CurrentFloor);
void openTheDoor()
{
/*
    INT0 ISR:
    Prevent the door from closing
    Or to Force the door to be opened
*/
doorOpenStatus = 1;

// Code here

delay_ms(5000);
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
        if (Direction){
            // 7 Segment
            if (Up[currentFloor]){
                stopped = 1;
                stepper_vDown();
                delay_ms(20);
                Up[currentFloor] = 0;
                openTheDoor();
                delay_ms(5000);
                // Close Door
            }
            temp = CheckUp(Up, currentFloor);
            if (temp != 404){
                stopped = 0;
                stepper_vUp();
                delay_ms(20);
                currentFloor++;
                // 7 Segment
            } else
            {
                Direction = 0;
            }
            if (currentFloor == 4){
                Direction = 0;
            }
        }
        if (!Direction) {
            if (Down[currentFloor] != CheckButtonOut(currentFloor) || Floors[i] != CheckButtonIn(currentFloor)){
                stopped = 1;
                stepper_vDown();
                delay_ms(20);
                Down[currentFloor] = CheckButtonOut(currentFloor);
                Floors[i] = CheckButtonIn(currentFloor);
                // Open Door
                delay_ms(5000);
                // Close Door
            }
            temp = CheckDown(Down, currentFloor);
            if (temp != 404){
                stopped = 0;
                stepper_vDown();
                delay_ms(20);
                currentFloor--;
                // 7 Segment
            } else
            {
                Direction = 1;
            }
            if (currentFloor == 0){
                Direction = 1;
            }
        }
//		if(floor4Btn == 0)
//		{
//			// Wait 5 seconds to close the door
//			delay_ms(5000);
//			LED_vTurnOn('3', 7);
//			stepper_vUp();
//			delay_ms(10);
//			currentFloor = 4;
//		}
//
//		if(floor0Btn == 0)
//		{
//			LED_vTurnOff('3', 7);
//			stepper_vDown();
//			delay_ms(10);
//			currentFloor = 0;
//		}
	}
}
void openTheDoorI() interrupt 0
{
    if(stopped){
        openTheDoor();
    }
}
int CheckButtonIn(int CurrentFloor){
    floor0Btn = button_u8read('0', CurrentFloor);
    return floor0Btn;
}
int CheckButtonOut(int CurrentFloor){
    if (!Direction && CurrentFloor != 0){
        floor1Btn = button_u8read('2', CurrentFloor - 1);
    } else if (Direction && CurrentFloor != 4){
        floor1Btn = button_u8read('2', CurrentFloor + 4);
    }
		return floor1Btn;
}
int CheckUp(unsigned int floorDir[5], unsigned int floorNumber){
    for (i = floorNumber; i < 5 ; ++i) {
        if (Floors[i] != CheckButtonIn(i)){
            return i;
        }
        if (floorDir[i] != CheckButtonOut(i)){
            return i;
        }
    }
    return 404;
}
int CheckDown(unsigned int floorDir[5], unsigned int floorNumber){
    for (i = floorNumber; i >= 0 ; --i) {
        if (Floors[i] != CheckButtonIn(i)){
            return i;
        }
        if (floorDir[i] != CheckButtonOut(i)){
            return i;
        }
    }
    return 404;
}