#include <REGX51.H>
#include "DIO.h"
#include "interrupt.h"
#include "std_macros.h"

void interrupt_vInit()
{
	// Write 1 on bit (EA) in IE (Interrupt Enable Register)
	SET_BIT(IE, 7);
}

void interrupt_vEnableExternal(unsigned char interruptNumber)
{
	if (interruptNumber == 0)
	{	
		// Enable EX0 (BIT 0 in IE Register)
		// Enable IT0 (BIT 0 in TCON Register)  -> 1 (Edge Sensitive)
		SET_BIT(IE, 0);	
		SET_BIT(TCON, 0);
	}
	
	else if (interruptNumber == 1)
	{
		// Enable EX1 (BIT 2 in IE Register)
		// Enable IT1 (BIT 2 in TCON Register)  -> 1 (Edge Sensitive)
		SET_BIT(IE, 2);
		SET_BIT(TCON, 2);
	}
}
