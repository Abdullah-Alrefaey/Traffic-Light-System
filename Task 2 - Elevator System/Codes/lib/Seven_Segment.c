#include<REG51F380.H>
#include "DIO.h"
#include "std_macros.h"


unsigned char seg[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char value;

void SevenSegment_SetUp(unsigned char portName)
{
	DIO_set_port_direction(portName, 1);
}

void SevenSegment_Display(unsigned char portName, unsigned char value)
{
	DIO_write_port(portName, seg[value]);
}