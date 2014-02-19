/** @file   system.h
    @author Martin Steinke
    @date   15 May 2007
    @brief  System specific definitions

    @note   using code from M. P. Hayes, UCECE.

*/
#ifndef SYSTEM_H
#define SYSTEM_H

/* Data typedefs.  */
//#include <stdint.h>
//typedef uint8_t bool;

/* Useful macros.  */
#define BIT(X) (1 << (X))

/* Clock frequency Hz.  */
#define F_CPU 1000000

void system_init (void);

#endif
