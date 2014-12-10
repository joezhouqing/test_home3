// This file has been prepared for Doxygen automatic documentation generation.
/*! \file ********************************************************************
*
* Atmel Corporation
*
* - File              : main.h
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
#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

    // Macro definitions
    #define sbi(port,bit)  (port |= (1<<bit))   //<! set bit in port
    #define cbi(port,bit)  (port &= ~(1<<bit))  //<! clear bit in port


    /*! \brief Enumeration of states, starting at 10.
     */
    typedef enum
    {

        ST_AVR_IDLE = 10,           //<! Idle state, before the phone is connected
        ST_AVR_INIT_MODEM,          //<! This state will call the modem init function
        ST_AVR_READY,               //<! Ready state, waiting for new message or key input

        ST_AVR_NO_ECHO,             //<! State to give error message to user during API_modem_init()
        ST_AVR_WRONG_STORAGE,       //<! State to give error message to user during API_modem_init()
        ST_AVR_WRONG_OPTION,        //<! State to give error message to user during API_modem_init()

        ST_AVR_NEW_SMS,             //<! Will display that a new message has arrived, user must push enter to read
        ST_AVR_NEW_SMS_function,    //<! In this state the index of the new message will be extracted

        ST_AVR_DELETE,              //<! Display "DELETE MESSAGE"
        ST_AVR_DELETE_function,     //<! Call the API_delete() function
        ST_AVR_READ,                //<! Display "READ MESSAGE"
        ST_AVR_READ_function,       //<! Call API_readmsg()

        ST_AVR_DISPLAY,             //<! Display new message

        ST_AVR_SEND,                //<! Dispaly "SEND SMS  "
        ST_AVR_SEND_function        //<! Call API_sendmsg
    }states;


     /*! \brief Enumeration of key inputs
     */
    typedef enum
    {

        KEY_NULL,                             //0
        KEY_ENTER,                            //1
        KEY_NEXT,                             //2
        KEY_PREV,                             //3
        KEY_PLUS,                             //4
        KEY_MINUS,                            //5
    }input;


    void Initialization(void);
    unsigned char StateMachine(char state, unsigned char stimuli);
    char getInput(void);

#endif
