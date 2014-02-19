/** @file   timer.c
    @author Martin Steinke
    @date   Feb 2014
    @brief  Timer module
    
    @note using code from M. P. Hayes, UCECE.
*/

#include <msp430.h>
#include "timer.h"
#include "system.h"

/* Timer/counter1 is a 16-bit counter with prescale options 1, 2, 4,
   8, 16, 32 and 64.  With F_CPU = 1e6 this corresponds to clock rates of
   1 MHz, 500 kHz, 250 kHz, 125 kHz, 62.5 kHz, 31.25 kHz and 15.625 kHz.

#if TIMER_CLOCK_DIVISOR == 1
#define TCCR1B_INIT 0x01
#elif TIMER_CLOCK_DIVISOR == 8
#define TCCR1B_INIT 0x02
#elif TIMER_CLOCK_DIVISOR == 64
#define TCCR1B_INIT 0x03
#elif TIMER_CLOCK_DIVISOR == 256
#define TCCR1B_INIT 0x04
#elif TIMER_CLOCK_DIVISOR == 1024
#define TCCR1B_INIT 0x05
#else
#error Invalid TIMER_CLOCK_DIVISOR
#endif


/** Initialise timer.  */
void timer_init (void)
{
    /* Start timer in normal mode so that it rolls over at 65535 to 0.  */
    TCCR1A = 0x00;
    TCCR1B = TCCR1B_INIT;
    TCNT1 = 0;
}


/** Get current time:
    @return current time in ticks.  */
timer_tick_t timer_get (void)
{
    return TCNT1;
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
