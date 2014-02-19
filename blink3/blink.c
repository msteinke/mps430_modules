// blink3

#include <msp430.h>
#include "../modules/system.h"

void delay(unsigned int delay)
{
        unsigned int i;
        for (i = 0; i < delay; i++) asm("nop");
}

int main()
{
        //WDTCTL = WDTPW + WDTHOLD;       // Stop WDT
	system_init();

        P1DIR |= BIT0;

        while(1) {
                P1OUT ^= BIT0;
                delay(100);
        }
        return 0;
}

