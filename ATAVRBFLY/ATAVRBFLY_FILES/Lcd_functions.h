// This file has been prepared for Doxygen automatic documentation generation.
/*! \file ********************************************************************
*
* Atmel Corporation
*
* - File              : Lcd_functions.h
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
#ifndef __LCD_FUNCTIONS_H_INCLUDED
#define __LCD_FUNCTIONS_H_INCLUDED

    //Functions
    void LCD_puts_f(char __flash *pFlashStr, char scrollmode);
    void LCD_puts(char *pStr, char scrollmode);
    void LCD_UpdateRequired(char update, char scrollmode);
    void LCD_putc(char digit, char character);
    void LCD_Clear(void);
    void LCD_Colon(char show);
    void LCD_FlashReset(void);
    char SetContrast(char input);
#endif
