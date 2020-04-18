#include "button.h"
#include "DIO.h"

void button_vInit(unsigned char portName, unsigned char pinNumber)
{
	DIO_vsetPINDir(portName, pinNumber, '1');
}

unsigned char button_u8read(unsigned char portName,unsigned char pinNumber)
{
	unsigned int x;
	x = (int) DIO_u8read(portName, pinNumber);
	return x;
}

