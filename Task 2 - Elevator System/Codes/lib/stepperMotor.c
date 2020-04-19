#include <REGX51.H>
#include "delay.h"
#include "DIO.h"
#include "interrupt.h"
#include "stepperMotor.h"
#include "std_macros.h"

void stepper_vInit()
{
	DIO_vsetPINDir('1', 0, 0);
	DIO_vsetPINDir('1', 1, 0);
	DIO_vsetPINDir('1', 2, 0);
	DIO_vsetPINDir('1', 3, 0);
}

void stepper_vUp()
{	
	// 0011
	DIO_write_low_nibble('1', 3);
	delay_ms(250);
	
	// 0110
	DIO_write_low_nibble('1', 6);
	delay_ms(250);
	
	// 1100
	DIO_write_low_nibble('1', 12);
	delay_ms(250);
	
	// 1001
	DIO_write_low_nibble('1', 9);
	delay_ms(250);
}

void stepper_vDown()
{	
	// 1100
	DIO_write_low_nibble('1', 12);
	delay_ms(250);
	
	// 0110
	DIO_write_low_nibble('1', 6);
	delay_ms(250);
	
	// 0011
	DIO_write_low_nibble('1', 3);
	delay_ms(250);
	
	// 1001
	DIO_write_low_nibble('1', 9);
	delay_ms(250);
}

//void moveToFloor(unsigned char floorNumber)
//{
//	unsigned char i = 0;
//	for(i=0; i<floorNumber; i++)
//	{
//		
//	}
//}	


