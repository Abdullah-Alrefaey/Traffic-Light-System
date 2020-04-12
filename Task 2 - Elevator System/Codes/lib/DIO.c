#include <REG51F380.H>
#include "DIO.h"
#include "std_macros.h"


void DIO_vsetPINDir(unsigned char portName, unsigned char pinNumber, unsigned char direction)
{
	// To Set PIN as Output
	// Write 1 in PnMDOUT ->(Enable Push-Pull Mode)
	
	// To Set PIN as Input
	// Write 0 in PnMDOUT ->(Enable Open-Drain Mode)
	// Write 1 in the specific bit in its PORT
	
	switch(portName)
	{
		case '0':
			if(direction == 1)
			{
				// Set the direction of the given pin in port 0 as output
				SET_BIT(P0MDOUT, pinNumber);
			}
			else
			{
				// Set the direction of the given pin in port 0 as input
				SET_BIT(P0MDOUT, pinNumber);
				SET_BIT(P0, pinNumber);
			}
			break;
			
		case '1':
			if(direction == 1)
			{
				// Set the direction of the given pin in port 1 as output
				SET_BIT(P1MDOUT, pinNumber);
			}
			else
			{
				// Set the direction of the given pin in port 1 as input
				SET_BIT(P1MDOUT, pinNumber);
				SET_BIT(P1, pinNumber);
			}
			break;
			
		case '2':
			if(direction == 1)
			{
				// Set the direction of the given pin in port 2 as output
				SET_BIT(P2MDOUT, pinNumber);
			}
			else
			{
				// Set the direction of the given pin in port 2 as input
				SET_BIT(P2MDOUT, pinNumber);
				SET_BIT(P2, pinNumber);
			}
			break;
			
		case '3':
			if(direction == 1)
			{
				// Set the direction of the given pin in port 3 as output
				SET_BIT(P3MDOUT, pinNumber);
			}
			else
			{
				// Set the direction of the given pin in port 3 as input
				SET_BIT(P3MDOUT, pinNumber);
				SET_BIT(P3, pinNumber);
			}
			break;
			
		case '4':
			if(direction == 1)
			{
				// Set the direction of the given pin in port 4 as output
				SET_BIT(P4MDOUT, pinNumber);
			}
			else
			{
				// Set the direction of the given pin in port 4 as input
				SET_BIT(P4MDOUT, pinNumber);
				SET_BIT(P4, pinNumber);
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
			
		case '4':
			if(outputvalue == 1)
			{
				// Set the value of the given pin in port 4 as High
				SET_BIT(P4, pinNumber);
			}
			else
			{
				// Set the value of the given pin in port 4 as Low
				CLR_BIT(P4, pinNumber);
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
		
		case '4':
			// Read the value from the given pin in port 4
			return_value = READ_BIT(P4, pinNumber);
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
		
		case '4':
			// Toggle the value of the given pin in port 4
			TOG_BIT(P4, pinNumber);
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
			if (direction == 1)
			{
				P0MDOUT = 0xFF;
			}
			else
			{
				P0MDOUT = 0x00;
				P0 = 0xFF;
			}
			break;
			
		case '1':
			// set the direction of port 1
			if (direction == 1)
			{
				P1MDOUT = 0xFF;
			}
			else
			{
				P1MDOUT = 0x00;
				P1 = 0xFF;
			}
			break;
			
		case '2':
			// set the direction of port 2
			if (direction == 1)
			{
				P2MDOUT = 0xFF;
			}
			else
			{
				P2MDOUT = 0x00;
				P2 = 0xFF;
			}
			break;
			
		case '3':
			// set the direction of port 3
			if (direction == 1)
			{
				P3MDOUT = 0xFF;
			}
			else
			{
				P3MDOUT = 0x00;
				P3 = 0xFF;
			}
			break;
			
		case '4':
			// set the direction of port 4
			if (direction == 1)
			{
				P4MDOUT = 0xFF;
			}
			else
			{
				P4MDOUT = 0x00;
				P4 = 0xFF;
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
		
		case '4':
			P4 = portValue; //Write the given value to the port 4
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
		
		case '4':
			// read the value of port 4
			return_val = P4;
			break;
		
		default:
			break;
	}
	return return_val;
}
