/** @file   pacer.h
    @author Martin C. Steinke
    @date   18 February 2014
    @brief  Paced loop for MSP430 Laucnhpad from TI

    @defgroup pacer Paced loop module
    
    This module uses code from M. P. Hayes, UCECE, 23 August 2010.

    This module provides support for paced loops by abstracting a
    hardware timer.

    Here's a simple example for a paced loop that operates at 1 kHz.

       @code
       #include "pacer.h"

       void main (void)
       {
           pacer_init (1000);

           while (1)
           {
               pacer_wait ();

               // Do something.
           }
        }
       @endcode
*/


#ifndef PACER_H
#define PACER_H

#include "system.h"

/** Define size of pacer rates.  */
typedef uint16_t pacer_rate_t;


/** Wait for the next pacer tick.  */
extern void pacer_wait (void);


/** Initialise pacer:
    @param pacer_rate rate in Hz.  */
extern void pacer_init (pacer_rate_t pacer_rate);

#endif /* PACER_H  */
