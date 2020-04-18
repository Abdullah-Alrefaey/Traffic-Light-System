#include <REGX51.H>
#include "DIO.h"
#include "std_macros.h"


void DIO_vsetPINDir(unsigned char portName, unsigned char pinNumber, unsigned char direction)
{
	// To Set PIN as Output
	// Write 0 in Pn
	
	// To Set PIN as Input
	// Write 1 in Pn
	
	switch(portName)
	{
		case '0':
			if(direction == '0')
			{
				// Set the direction of the given pin in port 0 as output
				CLR_BIT(P0, pinNumber);
			}
			else
			{
				// Set the direction of the given pin in port 0 as input
				SET_BIT(P0, pinNumber);
			}
			break;
			
		case '1':
			if(direction == '0')
			{
				// Set the direction of the given pin in port 1 as output
				CLR_BIT(P1, pinNumber);
			}
			else
			{
				// Set the direction of the given pin in port 1 as input
				SET_BIT(P1, pinNumber);
			}
			break;
			
		case '2':
			if(direction == '0')
			{
				// Set the direction of the given pin in port 2 as output
				CLR_BIT(P2, pinNumber);
			}
			else
			{
				// Set the direction of the given pin in port 2 as input
				SET_BIT(P2, pinNumber);
			}
			break;
			
		case '3':
			if(direction == '0')
			{
				// Set the direction of the given pin in port 3 as output
				CLR_BIT(P3, pinNumber);
			}
			else
			{
				// Set the direction of the given pin in port 3 as input
				SET_BIT(P3, pinNumber);
			}
			break;
		
		default: 
			break;
	}
}


void DIO_write(unsigned char portName, unsigned char pinNumber, unsigned char outputvalue)
{
	switch(portName)
	{
		case '0':
			if(outputvalue == 1)
			{
				// Set the value of the given pin in port 0 as High
				SET_BIT(P0, pinNumber);
			}
			else
			{
				// Set the value of the given pin in port 0 as Low
				CLR_BIT(P0,pinNumber);
			}
			break;
			
		case '1':
			if(outputvalue == 1)
			{
				// Set the value of the given pin in port 1 as High
				SET_BIT(P1, pinNumber);
			}
			else
			{
				// Set the value of the given pin in port 1 as Low
				CLR_BIT(P1, pinNumber);
			}
			break;
			
		case '2':
			if(outputvalue == 1)
			{
				// Set the value of the given pin in port 2 as High
				SET_BIT(P2, pinNumber);
			}
			else
			{
				// Set the value of the given pin in port 2 as Low
				CLR_BIT(P2, pinNumber);
			}
			break;
			
		case '3':
			if(outputvalue == 1)
			{
				// Set the value of the given pin in port 3 as High
				SET_BIT(P3, pinNumber);
			}
			else
			{
				// Set the value of the given pin in port 3 as Low
				CLR_BIT(P3, pinNumber);
			}
			break;

		default:
			break ;
	}
}


unsigned char DIO_u8read(unsigned char portName, unsigned char pinNumber)
{
	unsigned char return_value = 0;
	switch(portName)
	{
		case '0':
			// Read the value from the given pin in port 0
			return_value = READ_BIT(P0, pinNumber);
			break;
		
		case '1':
			// Read the value from the given pin in port 1
			return_value = READ_BIT(P1, pinNumber);
			break;
		
		case '2':
			// Read the value from the given pin in port 2
			return_value = READ_BIT(P2, pinNumber);
			break;
		
		case '3':
			// Read the value from the given pin in port 3
			return_value = READ_BIT(P3, pinNumber);
			break;
		
		default: 
			break;
	}
	return return_value;
}


void DIO_toggle(unsigned char portName, unsigned char pinNumber)
{
	switch(portName)
	{
		case '0':
			// Toggle the value of the given pin in port 0
			TOG_BIT(P0, pinNumber);
			break;
		
		case '1':
			// Toggle the value of the given pin in port 1
			TOG_BIT(P1, pinNumber);
			break;
		
		case '2':
			// Toggle the value of the given pin in port 2
			TOG_BIT(P2, pinNumber);
			break;
		
		case '3':
			// Toggle the value of the given pin in port 3
			TOG_BIT(P3, pinNumber);
			break;
		
		default:
			break;
	}
}


void DIO_set_port_direction(unsigned char portName, unsigned char direction)
{
	switch(portName)
	{
		case '0':
			// set the direction of port 0
			if (direction == 0)
			{
				P0 = 0x00;
			}
			else
			{
				P0 = 0xFF;
			}
			break;
			
		case '1':
			// set the direction of port 1
			if (direction == 0)
			{
				P1 = 0x00;
			}
			else
			{
				P1 = 0xFF;
			}
			break;
			
		case '2':
			// set the direction of port 2
			if (direction == 0)
			{
				P2 = 0x00;
			}
			else
			{
				P2 = 0xFF;
			}
			break;
			
		case '3':
			// set the direction of port 3
			if (direction == 0)
			{
				P3 = 0x00;
			}
			else
			{
				P3 = 0xFF;
			}
			break;		
		
		default:
			break ;
	}
	
}


void DIO_write_port(unsigned char portName, unsigned char portValue)
{
	switch(portName)
	{
		case '0':
			P0 = portValue; //Write the given value to the port 0
			break;
				
		case '1':
			P1 = portValue; //Write the given value to the port 1
			break;
		
		case '2':
			P2 = portValue; //Write the given value to the port 2
			break;
		
		case '3':
			P3 = portValue; //Write the given value to the port 3
			break;
		
		default:
			break;
	}
}

unsigned char DIO_read_port(unsigned char portName)
{
	unsigned char return_val = 0;
	
	switch(portName)
	{
		case '0':
			// read the value of port 0 
			return_val = P0;
			break;
		
		case '1':
			// read the value of port 1 
			return_val = P1;
			break;
		
		case '2':
			// read the value of port 2 
			return_val = P2;
			break;
		
		case '3':
			// read the value of port 3 
			return_val = P3;
			break;
		
		default:
			break;
	}
	return return_val;
}
void DIO_write_high_nibble(unsigned char portName, unsigned char value)
{
	value<<=4;
	switch(portName)
	{
		case '0':
			P0&=0x0f;
			P0|=value;
			break;
		case '1':
			P1&=0x0f;
			P1|=value;
			break;
		case '2':
			P2&=0x0f;
			P2|=value;
			break;
		case '3':
			P3&=0x0f;
			P3|=value;
			break;
	}
}
void DIO_write_low_nibble(unsigned char portName, unsigned char value)
{
	switch(portName)
	{
		case '0':
			P0&=0xf0;
			P0|=value;
			break;
		case '1':
			P1&=0xf0;
			P1|=value;
			break;
		case '2':
			P2&=0xf0;
			P2|=value;
			break;
		case '3':
			P3&=0xf0;
			P3|=value;
			break;
	}
}
void DIO_write_nibble(unsigned char portName, unsigned char value, unsigned char mode)
{
	switch(mode)
	{
		case '0':
			DIO_write_low_nibble(portName, value);
			break;
		case '1':
			DIO_write_high_nibble(portName, value);
			break;
	}
}
