/**
 * file: 
LT1_Task1_Mahat.c
 * Author: Bipin Mahat
 * Date: 10/09/2024
 * Description: . Develop an application that will simulate arming and disarming a 
security system by using two 
pushbuttons for task1.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */
/* TODO: insert other definitions and declarations here. */
void SW2_GPIOC_IRQHANDLER(void) /*Interrupt Service Routine for SW2*/
{
/* clear interrupt flag set by button SW2 connected to pin PTC6 */
 GPIO_PortClearInterruptFlags(GPIOC, 1U << 6U);
 GPIO_PinWrite(GPIOC, 16U, 1U); /* make pin PTC16 High */
 LED_RED_ON(); /* turn ON RED LED */
 LED_GREEN_OFF();
 PRINTF("System Status: Armed\n");
}
void SW3_GPIOA_IRQHANDLER(void) /*Interrupt Service Routine for SW3*/
{
/* clear interrupt flag set by button SW3 connected to pin PTA4 */
 GPIO_PortClearInterruptFlags(GPIOA, 1U << 4U);
 GPIO_PinWrite(GPIOC, 16U, 0U); /* make pin PTC16 Low */
 LED_RED_OFF(); /* turn OFF RED LED */
 LED_GREEN_ON();
 PRINTF("System Status: Disarmed\n");
}
/*
 * @brief Application entry point.
 */
int main(void) {
 
/* Init board hardware. */

 
BOARD_InitBootPins();
 
BOARD_InitBootClocks();
 
BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
 
/* Init FSL debug console. */
 
BOARD_InitDebugConsole();
#endif
 
LED_RED_OFF();
 
LED_GREEN_ON();
 
GPIO_PinWrite(GPIOC, 16U, 0U);
 
PRINTF("Lab Test 1 - Bipin Mahat\n Press SW2 to Arm System\n Press SW3 to Disarm 
System\n System status: Disarmed\n");
 
/* Force the counter to be placed into memory. */
 
volatile static int i = 0 ;
 
/* Enter an infinite loop, just incrementing a counter. */
 
while(1) {
 
i++ ;
 
/* 'Dummy' NOP to allow source level single stepping of
 
tight while() loop */
 
__asm volatile ("nop");
 
}
 
return 0 ;
}