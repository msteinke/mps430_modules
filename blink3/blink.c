// blink3

#include <msp430.h>
#include "../modules/system.h"
#include "../modules/timer.h"
#include "../modules/pacer.h"
/*
void delay(unsigned int delay)
{
        unsigned int i;
        for (i = 0; i < delay; i++) asm("nop");
}
*/
int main(void)
{
        //WDTCTL = WDTPW + WDTHOLD;       // Stop WDT
	system_init();
	pacer_init(10);
	
	P1DIR |= BIT0;
	
	while(1)
	{	
		pacer_wait();
		
		P1OUT ^= BIT0;
	}
	return 0;
}

/*
 * 
 * 
 *     #include "pacer.h"

       void main (void)
       {
           pacer_init (1000);

           while (1)
           {
               pacer_wait ();

               // Do something.
           }
        }
*/
