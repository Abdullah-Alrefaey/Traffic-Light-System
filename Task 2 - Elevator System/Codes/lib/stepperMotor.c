#include <REG51F380.H>
#include "delay.h"
#include "DIO.h"
#include "interrupt.h"
#include "std_macros.h"

void stepper_vInit()
{
	DIO_vsetPINDir('1', 0, 1);
	DIO_vsetPINDir('1', 1, 1);
	DIO_vsetPINDir('1', 2, 1);
	DIO_vsetPINDir('1', 3, 1);
}

void stepper_vUp()
{	
	// 0011
	SET_BIT(P1, 0);
	SET_BIT(P1, 1);
	CLR_BIT(P1, 2);
	CLR_BIT(P1, 3);
	delay_ms(100);
	
	// 0110
	SET_BIT(P1, 1);
	SET_BIT(P1, 2);
	CLR_BIT(P1, 0);
	CLR_BIT(P1, 3);
	delay_ms(100);
	
	// 1100
	SET_BIT(P1, 2);
	SET_BIT(P1, 3);
	CLR_BIT(P1, 0);
	CLR_BIT(P1, 1);
	delay_ms(100);
	
	// 1001
	SET_BIT(P1, 0);
	SET_BIT(P1, 3);
	CLR_BIT(P1, 1);
	CLR_BIT(P1, 2);
	delay_ms(100);
}

void stepper_vDown()
{	
	
	
	// 1100
	SET_BIT(P1, 2);
	SET_BIT(P1, 3);
	CLR_BIT(P1, 0);
	CLR_BIT(P1, 1);
	delay_ms(100);
	
	// 0110
	SET_BIT(P1, 1);
	SET_BIT(P1, 2);
	CLR_BIT(P1, 0);
	CLR_BIT(P1, 3);
	delay_ms(100);
	
	// 0011
	SET_BIT(P1, 0);
	SET_BIT(P1, 1);
	CLR_BIT(P1, 2);
	CLR_BIT(P1, 3);
	delay_ms(100);
	
	
	// 1001
	SET_BIT(P1, 0);
	SET_BIT(P1, 3);
	CLR_BIT(P1, 1);
	CLR_BIT(P1, 2);
	delay_ms(100);
	
}

//void moveToFloor(unsigned char floorNumber)
//{
//	unsigned char i = 0;
//	for(i=0; i<floorNumber; i++)
//	{
//		
//	}
//}	


