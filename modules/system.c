/** @file   system.c
    @author Martin Steinke
    @date   Feb 2014
    @brief  UCFK system initialisation
    
    @note   using code from M. P. Hayes, UCECE.
*/
#include "system.h"
#include <avr/wdt.h>


static void system_clock_init (void)
{
    /* Switch 1 MHz CPU clock to 8 MHz.  */
    //CLKPR = BIT (CLKPCE);
    //CLKPR = 0;

    /* set MSP430 clock to 1 MHz*/
    BCSCTL1 = CALBC1_1MHZ;  
    DCOCTL = CALDCO_1MHZ;
}


static void system_watchdog_timer_init (void)
{
    //wdt_reset ();

    /* Clear WDRF in MCUSR.  */
    //MCUSR &= ~BIT (WDRF);
    /* Write logical one to WDCE and WDE and keep old prescaler
       setting to prevent unintentional time-out.  */
    //WDTCSR |= BIT (WDCE) | BIT (WDE);

    /* Turn off watchdog timer.  */
    WDTCTL = WDTPW + WDTHOLD;     
}


void system_init (void)
{
    system_clock_init ();
    system_watchdog_timer_init ();
}



