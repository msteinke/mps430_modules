/** @file   system.c
    @author Martin Steinke
    @date   Feb 2014
    @brief  UCFK system initialisation
    
    @note   using code from M. P. Hayes, UCECE.
*/
#include "system.h"
#include <msp430.h>
//#include <avr/wdt.h>


static void system_clock_init (void)
{
    /* set MSP430 clock to 1 MHz*/
    BCSCTL1 = CALBC1_1MHZ;  
    DCOCTL = CALDCO_1MHZ;
}


static void system_watchdog_timer_init (void)
{
    /* Turn off watchdog timer.  */
    WDTCTL = WDTPW + WDTHOLD;     
}


void system_init (void)
{
    system_clock_init ();
    system_watchdog_timer_init ();
}



