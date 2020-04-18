#include <REGX51.H>
#include "DIO.h"
#include "std_macros.h"

#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_


/*
Function Name        : stepper_vInit
Function Returns     : void
Function Arguments   : 
Function Description : 
*/
void stepper_vInit();

/*
Function Name        : stepper_vUp
Function Returns     : void
Function Arguments   : unsigned char portName
Function Description : Rotate the stepper in Counter Clockwise direction (Left)
*/
void stepper_vUp();


/*
Function Name        : stepper_vDown
Function Returns     : void
Function Arguments   : 
Function Description : Rotate the stepper in Clockwise direction (Right)
*/
void stepper_vDown();


/*
Function Name        : moveUpToFloor
Function Returns     : void
Function Arguments   : unsigned char floorNumber
Function Description : 
*/
void moveUpToFloor(unsigned char floorNumber);

/*
Function Name        : moveDownToFloor
Function Returns     : void
Function Arguments   : unsigned char floorNumber
Function Description : 
*/
void moveDownToFloor(unsigned char floorNumber);

#endif