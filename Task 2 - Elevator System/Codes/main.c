#include <REGX51.H>
#include "lib/delay.h"
#include "lib/std_macros.h"
#include "lib/DIO.h"
#include "lib/LED.h"
#include "lib/button.h"
#include "lib/interrupt.h"
#include "lib/stepperMotor.h"
#include "lib/Seven_Segment.h"
#include <stdio.h>

unsigned char persons = 0;            // Number of persons
unsigned char i_warn;                // Warning counter in the loop
unsigned char doorOpenStatus = 1;    // Initially the door is opened
unsigned char currentFloor = 0;        // Current Floor of the Elevator
unsigned int floor0Btn, floor1Btn, floor2Btn, floor3Btn, floor4Btn;
unsigned int Up[5] = {1, 1, 1, 1, 1};
unsigned int Down[5] = {1, 1, 1, 1, 1};
unsigned int Floors[5] = {1, 1, 1, 1, 1};
int Direction = 1; //Up is True, Down is False
int i, temp, temp2, UpCalled, DownCalled;
int stopped = 1;

int CheckUp(unsigned int floorDir[5], unsigned int floorNumber, int UpOrDown), CheckDown(unsigned int floorDir[5],
                                                                                         unsigned int floorNumber,
                                                                                         int UpOrDown);

int CheckButtonIn(int CurrentFloor);

int CheckButtonOut(int UpOrDown, int CurrentFloor);

int toggle(int number);
void UpdateStates(){
    temp2 = CheckDown(Down, currentFloor, 0);
    temp = CheckUp(Up, currentFloor, 1);
    UpCalled = CheckUp(Up, currentFloor, 1);
    DownCalled = CheckUp(Down, currentFloor, 0);
}
void openTheDoor() {
/*
    INT0 ISR:
    Prevent the door from closing
    Or to Force the door to be opened
*/
    LED_vTurnOn('0', 5);
    doorOpenStatus = 1;

// Code here

    delay_ms(1000);
    LED_vTurnOff('0', 5);
    doorOpenStatus = 0;
}

void personIn()

interrupt 2
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
for(
i_warn = 0;
i_warn<100; i_warn++)
{
LED_vToggle('3', 7);
delay_ms(10);
}
LED_vTurnOff('3', 7);
}
}

int main() {
    // Initialization of stepper motor and external interrupts
    stepper_vInit();
    interrupt_vInit();
    interrupt_vEnableExternal(0);
    interrupt_vEnableExternal(1);

    // Initialize the warning LED of maximum persons
    LED_vInit('3', 7);
    LED_vTurnOff('3', 7);

    // Initialize the  LED of Opened Door
    LED_vInit('0', 5);
    LED_vTurnOff('0', 5);

    // Initialize interrupts Buttons
    button_vInit('3', 2);
    button_vInit('3', 3);

    // Initialize Elevator Buttons
    button_vInit('0', 0);
    button_vInit('0', 1);
    button_vInit('0', 2);
    button_vInit('0', 3);
    button_vInit('0', 4);
    button_vInit('2', 0);
    button_vInit('2', 1);
    button_vInit('2', 2);
    button_vInit('2', 3);
    button_vInit('2', 4);
    button_vInit('2', 5);
    button_vInit('2', 6);
    button_vInit('2', 7);

    SevenSegment_SetUp('1', 4);

    while (1) {
        SevenSegment_Display('1', (char) currentFloor);
        UpdateStates();
        if (Direction) {
            // 7 Segment
            if (Up[currentFloor] != CheckButtonOut(1, currentFloor) || Floors[i] != CheckButtonIn(currentFloor)) {
                stopped = 1;
                Up[currentFloor] = CheckButtonOut(1, currentFloor);
                Floors[i] = CheckButtonIn(currentFloor);
                openTheDoor();
                // Close Door
            }

            if (currentFloor < 4) {

                if (temp != 404 && temp != currentFloor) {
                    stopped = 0;
                    stepper_vUp();
                    delay_ms(20);
                    currentFloor++;
                    SevenSegment_Display('1', (char) currentFloor);
                    UpdateStates();
                    // 7 Segment
                } else if (temp2 == 404) {
                    if (UpCalled != 404 && currentFloor > 0 && UpCalled != currentFloor) {
                        stopped = 0;
                        stepper_vDown();
                        delay_ms(20);
                        currentFloor--;
                        SevenSegment_Display('1', (char) currentFloor);
                        UpdateStates();
                    }
                } else {
                    stopped = 1;
                    Direction = 0;
                }
            }
            if (temp == 404) {
                Direction = 0;
            }
            if (currentFloor == 4) {
                Direction = 0;
            }
        }
        if (!Direction) {
            if (Down[currentFloor] != CheckButtonOut(0, currentFloor) || Floors[i] != CheckButtonIn(currentFloor)) {
                stopped = 1;
                delay_ms(20);
                Down[currentFloor] = CheckButtonOut(0, currentFloor);
                Floors[i] = CheckButtonIn(currentFloor);
                openTheDoor();
            }

            if (currentFloor >= 0) {

                if (temp2 != 404 && temp2 != currentFloor) {
                    stopped = 0;
                    stepper_vDown();
                    delay_ms(20);
                    currentFloor--;
                    SevenSegment_Display('1', (char) currentFloor);
                    UpdateStates();
                    // 7 Segment

                } else if (temp == 404) {
                    if (DownCalled != 404 && currentFloor < 4 && DownCalled != currentFloor) {
                        stopped = 0;
                        stepper_vUp();
                        delay_ms(20);
                        currentFloor++;
                        SevenSegment_Display('1', (char) currentFloor);
                        UpdateStates();
                    }
                } else {
                    stopped = 1;
                    Direction = 1;
                }
            }
            if (temp2 == 404) {
                Direction = 1;
            }
            if (currentFloor <= 0) {
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

void openTheDoorI()

interrupt 0
{
if(stopped){
openTheDoor();

}
}

int CheckButtonIn(int CurrentFloor) {
    floor0Btn = button_u8read('0', CurrentFloor);
    return floor0Btn;
}

int CheckButtonOut(int UpOrDown, int But) {
    if (!UpOrDown && But != 0) {
        return button_u8read('2', But - 1);
    } else if (UpOrDown && But != 4) {
        return button_u8read('2', But + 4);
    }
    if (!UpOrDown) {
        return Down[But];
    } else {
        return Up[But];
    }

}

int CheckUp(unsigned int floorDir[5], unsigned int floorNumber, int UpOrDown) {
    for (i = floorNumber; i < 5; ++i) {
        if (Floors[i] != CheckButtonIn(i)) {
            return i;
        }
        if (floorDir[i] != CheckButtonOut(UpOrDown, i)) {
            return i;
        }
    }
    return 404;
}

int CheckDown(unsigned int floorDir[5], unsigned int floorNumber, int UpOrDown) {
    for (i = floorNumber; i >= 0; --i) {
        if (Floors[i] != CheckButtonIn(i)) {
            return i;
        }
        if (floorDir[i] != CheckButtonOut(UpOrDown, i)) {
            return i;
        }
    }
    return 404;
}

int toggle(int num) {
    if (num) {
        return 0;
    } else {
        return 1;
    }
}