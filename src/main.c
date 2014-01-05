#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <driverlib/sysctl.h>
#include <driverlib/uart.h>
#include <driverlib/gpio.h>
#include <driverlib/interrupt.h>
#include <driverlib/pin_map.h>
#include <inc/hw_memmap.h>
#include "main.h"
#include "matrix-driver.h"

static const Pin_t left_rows[5] = {PIN_E3, PIN_B4, PIN_E1, PIN_A5, PIN_A6};
static const Pin_t left_columns[3] = {PIN_E2, PIN_F1, PIN_A7};
 

int main( void ) {
  keymatrix_t * to_scan_left = init_matrix(&left_columns[0], 3, &left_rows[0], 5);
  keymatrix_t * to_scan_right = init_matrix((const Pin_t *) 0, 0, (const Pin_t *) 0, 0);
  // Clock (80 MHz)
  SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
  // UART
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
  GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
  UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, (UART_CONFIG_PAR_NONE | UART_CONFIG_STOP_ONE | UART_CONFIG_WLEN_8));
  
  UARTEnable(UART0_BASE);
  IntMasterEnable();
  while(1){
    printf("left:%05o right:%05o\r\n",(unsigned int) scan_matrix(to_scan_left),
	   (unsigned int) scan_matrix(to_scan_right));
  }
}
