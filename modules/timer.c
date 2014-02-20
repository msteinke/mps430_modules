/** @file   timer.c
    @author Martin Steinke
    @date   Feb 2014
    @brief  Timer module
    
    @note using code from M. P. Hayes, UCECE.
*/

#include <msp430.h>
#include "timer.h"
#include "system.h"

/* Timer/counterA is a 16-bit counter with prescale options 1, 2, 4
   and 8.  With F_CPU = 1e6 this corresponds to clock rates of
   1 MHz, 500 kHz, 250 kHz and 125 kHz.

#if TIMER_CLOCK_DIVISOR == 1
#define TACTL = TASSEL_2 + ID_0 + MC_2
#elif TIMER_CLOCK_DIVISOR == 2
#define TACTL = TASSEL_2 + ID_1 + MC_2
#elif TIMER_CLOCK_DIVISOR == 4
#define TACTL = TASSEL_2 + ID_2 + MC_2
#elif TIMER_CLOCK_DIVISOR == 8
#define TACTL = TASSEL_2 + ID_3 + MC_2
#else
#error Invalid TIMER_CLOCK_DIVISOR
#endif

*/
/** Initialise timer.  */
void timer_init (void)
{
    /* Start timer in continous mode so that it rolls over at 65535 to 0.
     * source clock from SMCLK.  */
    TACTL = TASSEL_2 + ID_3 + MC_2;    // <------ FIX THIS ID PROBLEM
}


/** Get current time:
    @return current time in ticks.  */
timer_tick_t timer_get (void)
{
    return TAR;
}
/** Set the timer to a desired time:
 *  @param the time (in ticks) to set the timer to.*/
void timer_set (timer_tick_t when)
{
	TAR = when;
}

/** Wait until specified time:
    @param when time to sleep until
    @return current time.  */
timer_tick_t timer_wait_until (timer_tick_t when)
{
    while (1)
    {
        timer_tick_t diff;
        timer_tick_t now;
        
        now = timer_get ();

        diff = now - when;

        if (diff < TIMER_OVERRUN_MAX)
            return now;
    }
}


/** Wait for specified period:
    @param period how long to wait
    @return current time.  */
timer_tick_t timer_wait (timer_tick_t period)
{
    return timer_wait_until (timer_get () + period);
}
