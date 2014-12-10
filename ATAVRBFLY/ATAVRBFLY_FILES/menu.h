// This file has been prepared for Doxygen automatic documentation generation.
/*! \file ********************************************************************
*
* Atmel Corporation
*
* - File              : menu.h
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


#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


/*! \brief Flash struct defining next state
 */
__flash typedef struct
{
    unsigned char state;        //!< State number
    unsigned char input;        //!< Stimuli that gives state transition
    unsigned char nextstate;    //!< New state after input
}MENU_NEXTSTATE;


/*! \brief Flash struct defining this state
 */
__flash typedef struct
{
    unsigned char state;        //!< This state
    char __flash *pText;        //!< Text to display on the LCD
    char (*pFunc)(char input);  //!< State function
}MENU_STATE;


//<! Menu text to be displayed
__flash char MT_IDLE[]                      = "ENTER IF CONNECTED";
__flash char MT_WAIT[]                      = "Waiting";
__flash char MT_READY[]                     = "AVR GSM";

__flash char MT_ECHO[]                      = "NO MODEM CONNECTED";
__flash char MT_STORAGE[]                   = "ERRONEOUS STORAGE";
__flash char MT_INDICATION[]                = "ERRONEOUS INDICATION";

__flash char MT_NEW[]                       = "NEW SMS";

__flash char MT_DELETE[]                    = "DELETE MESSAGE";
__flash char MT_READ[]                      = "READ MESSAGE";

__flash char MT_SEND[]                      = "SEND SMS";


//<! Next state table
MENU_NEXTSTATE menu_nextstate[] = {
    //  STATE                       INPUT       NEXT STATE
    {ST_AVR_IDLE,                KEY_ENTER,     ST_AVR_INIT_MODEM}, //Start
    {ST_AVR_READY,               KEY_PLUS,      ST_AVR_SEND},

    {ST_AVR_NO_ECHO,             KEY_ENTER,     ST_AVR_INIT_MODEM}, //Error with echo off command
    {ST_AVR_WRONG_STORAGE,       KEY_ENTER,     ST_AVR_INIT_MODEM}, //Error with storgae selection
    {ST_AVR_WRONG_OPTION,        KEY_ENTER,     ST_AVR_INIT_MODEM}, //Error with forwarding option

    {ST_AVR_NEW_SMS,             KEY_PLUS,      ST_AVR_READ},
    {ST_AVR_NEW_SMS,             KEY_MINUS,     ST_AVR_DELETE},

    {ST_AVR_DELETE,              KEY_PLUS,      ST_AVR_NEW_SMS},
    {ST_AVR_DELETE,              KEY_ENTER,     ST_AVR_DELETE_function},

    {ST_AVR_READ,                KEY_MINUS,     ST_AVR_NEW_SMS},
    {ST_AVR_READ,                KEY_ENTER,     ST_AVR_READ_function},

    {ST_AVR_DISPLAY,             KEY_MINUS,     ST_AVR_READY},

    {ST_AVR_DISPLAY,             KEY_PLUS,      ST_AVR_READY},

    {ST_AVR_DISPLAY,             KEY_ENTER,     ST_AVR_READY},

    {ST_AVR_DISPLAY,             KEY_NEXT,      ST_AVR_READY},

    {ST_AVR_DISPLAY,             KEY_PREV,      ST_AVR_READY},

    {ST_AVR_SEND,                KEY_ENTER,     ST_AVR_SEND_function},
    {ST_AVR_SEND,                KEY_MINUS,     ST_AVR_READY},

    {0,                          0,             0}
};


//<! State table
MENU_STATE menu_state[] = {
//  STATE                               STATE TEXT                  STATE_FUNC
    {ST_AVR_IDLE,                         MT_IDLE,                   NULL},
    {ST_AVR_INIT_MODEM,                   MT_WAIT,                   ST_init_phone},
    {ST_AVR_READY,                        MT_READY,                  NULL},

    {ST_AVR_NO_ECHO,                      MT_ECHO,                   NULL},
    {ST_AVR_WRONG_STORAGE,                MT_STORAGE,                NULL},
    {ST_AVR_WRONG_OPTION,                 MT_INDICATION,             NULL},

    {ST_AVR_NEW_SMS_function,             NULL,                      ST_get_index},
    {ST_AVR_NEW_SMS,                      MT_NEW,                    NULL},

    {ST_AVR_DELETE,                       MT_DELETE,                 NULL},
    {ST_AVR_DELETE_function,              NULL,                      ST_delete_msg},

    {ST_AVR_READ,                         MT_READ,                   NULL},
    {ST_AVR_READ_function,                NULL,                      ST_read},

    {ST_AVR_DISPLAY,                      NULL,                      NULL},

    {ST_AVR_SEND,                         MT_SEND,                   NULL},
    {ST_AVR_SEND_function,                NULL,                      ST_send},

    {0,                                   NULL,                      NULL},
};
#endif
