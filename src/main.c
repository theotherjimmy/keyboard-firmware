#include <stdbool.h>
#include <stdint.h>
#include <driverlib/sysctl.h>
#include <driverlib/uart.h>
#include <driverlib/gpio.h>
#include <driverlib/interrupt.h>
#include <driverlib/pin_map.h>
#include <inc/hw_memmap.h>
#include <inc/hw_gpio.h>
#include <inc/hw_types.h>
#include "main.h"
#include "nkro.h"
#include "matrix-driver.h"
#include "hid-report-generator.h"
#include "hid-keyboard.h"

static const Pin_t left_rows[5] = {PIN_C6, PIN_C7, PIN_D6, PIN_D7, PIN_F4};
static const Pin_t left_columns[3] = {PIN_C5, PIN_C4, PIN_B3};
static const Pin_t left_thumb_column[1] = {PIN_A2};
static const Pin_t left_thumb_row[6] = {PIN_A3, PIN_A4, PIN_B6, PIN_B7, PIN_F0, PIN_E0};

static const Pin_t right_rows[5] = {PIN_F1, PIN_E3, PIN_E2, PIN_E1, PIN_D3};
static const Pin_t right_columns[3] = {PIN_D2, PIN_D1, PIN_D0};
static const Pin_t right_thumb_column[1] = {PIN_A7};
static const Pin_t right_thumb_row[6] = {PIN_A6, PIN_A5, PIN_B4, PIN_E5, PIN_E4, PIN_B1};

int init_hw( void );

int main( void ) {
  keymatrix_t * to_scan_left;
  keymatrix_t * to_scan_right;
  keymatrix_t * to_scan_thumb_left;
  keymatrix_t * to_scan_thumb_right;
  init_hw( );
  to_scan_left = init_matrix( &left_columns[0], 3, &left_rows[0], 5 );
  to_scan_right = init_matrix( &right_columns[0], 3, &right_rows[0], 5 );
  to_scan_thumb_left = init_matrix( &left_thumb_row[0], 6, &left_thumb_column[0], 1 );
  to_scan_thumb_right = init_matrix( &right_thumb_row[0], 6, &right_thumb_column[0], 1 );
  USBDHIDKeyboardInit(0);
  while( 1 ){
    SysCtlDelay(100000);
    ScanCodesToReport( scan_matrix(to_scan_left), scan_matrix(to_scan_thumb_left),
		       scan_matrix(to_scan_right), scan_matrix(to_scan_thumb_right));
    while (!SendButtons()) ;
  }
}

int init_hw( void ) {
  // Clock (80 MHz)
  SysCtlClockSet( SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN );

  SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOA );
  SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOB );
  SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOC );
  SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOD );
  SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOE );
  SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOF );

  GPIOPinTypeUSBAnalog( GPIO_PORTD_BASE, GPIO_PIN_4 | GPIO_PIN_5 );

  // Special workarounds for PF0 and PD7
  // For more info lookup NMI mux issue on the LM4F
  HWREG( GPIO_PORTD_BASE + GPIO_O_LOCK ) = GPIO_LOCK_KEY;
  HWREG( GPIO_PORTD_BASE + GPIO_O_CR ) = GPIO_PIN_7;
  HWREG( GPIO_PORTD_BASE + GPIO_O_LOCK ) = 0;
  HWREG( GPIO_PORTF_BASE + GPIO_O_LOCK ) = GPIO_LOCK_KEY;
  HWREG( GPIO_PORTF_BASE + GPIO_O_CR ) = GPIO_PIN_0;
  HWREG( GPIO_PORTF_BASE + GPIO_O_LOCK ) = 0;

  IntMasterEnable();
  return 0;
}
