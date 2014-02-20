// blink3

#include <msp430.h>
#include "../modules/system.h"
#include "../modules/timer.h"
#include "../modules/pacer.h"

int main(void)
{
	system_init();
	pacer_init(10000);
	
	P1DIR |= BIT0;
	
	while(1)
	{	
		pacer_wait();
		
		P1OUT ^= BIT0;
	}
	return 0;
}

