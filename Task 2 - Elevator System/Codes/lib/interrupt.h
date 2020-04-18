#include <REGX51.H>
#include "DIO.h"
#include "std_macros.h"

#ifndef INTERRUPT_H_
#define INTERRUPT_H_


/*
Function Name        : interrupt_vInit
Function Returns     : void
Function Arguments   : 
Function Description : Enable the global interrupt bit (EA)
*/
void interrupt_vInit();


/*
Function Name        : interrupt_vEnableExternal
Function Returns     : void
Function Arguments   : unsigned char interruptNumber
Function Description : Enable External Interrupt 0 or 1
*/
void interrupt_vEnableExternal(unsigned char interruptNumber);


#endif