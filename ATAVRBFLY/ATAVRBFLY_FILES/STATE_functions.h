// This file has been prepared for Doxygen automatic documentation generation.
/*! \file ********************************************************************
*
* Atmel Corporation
*
* - File              : STATE_functions.h
* - Compiler          : IAR EWAAVR 4.11a
*
* - Support mail      : avr@atmel.com
*
* - Supported devices : All devices with a UART/USART can be used.
*                       The example is written for ATmega169
*
* - AppNote           : AVR323 - Interfacing GSM modems
*
* - Description       : Example of how to use AT-Commands to control a GSM modem
*
* $Revision: 1.1 $
* $Date: Tuesday, November 08, 2005 12:25:32 UTC $
*****************************************************************************/
#ifndef STATE_FUNCTIONS_H_INCLUDED
#define STATE_FUNCTIONS_H_INCLUDED

    char ST_init_phone(char input);
    char ST_get_index( char input );
    char ST_delete_msg( char input );
    char ST_read( char input );
    char ST_send(char input);

#endif
