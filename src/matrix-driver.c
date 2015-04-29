#include "matrix-driver.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <inc/hw_gpio.h>
#include <inc/hw_memmap.h>
#include <driverlib/sysctl.h>
#include <driverlib/gpio.h>

const uint32_t PIN_PORTS[PORT_COUNT] = {
	GPIO_PORTA_BASE, GPIO_PORTB_BASE,
	GPIO_PORTC_BASE, GPIO_PORTD_BASE,
	GPIO_PORTE_BASE, GPIO_PORTF_BASE,
};

keymatrix_t matrices[num_matrices];
uint32_t allocated = 0;

/* computations that use my pin enum that make things a bit easier*/
static inline uint32_t Pin_num(const Pin_t pin) {
	return 0x1 << ( pin & 0x7 ); }

static inline uint32_t Pin_port(const Pin_t pin) {
	return PIN_PORTS[pin >> 3]; }

char init_pin(Pin_t to_init, char inout){
	if ( to_init >= PIN_COUNT ) return true;
	(void (*[2])(uint32_t, uint8_t))
	{ GPIOPinTypeGPIOOutput,
			GPIOPinTypeGPIOInput }[ (inout) ? 1 : 0 ] ( Pin_port( to_init ),
								    Pin_num( to_init ) );
	GPIOPadConfigSet( Pin_port( to_init ), Pin_num( to_init ),
			  GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD );
	return false; }

keymatrix_t* init_matrix( const Pin_t *columns, uint32_t num_columns,
			  const Pin_t *rows,    uint32_t num_rows ){
	uint32_t counter;
	if ( ( allocated >= num_matrices ) ||
	     ( num_columns == 0 ) ||
	     ( num_rows == 0 ) )
		return ( keymatrix_t * ) NULL;
	for( counter = 0; counter < 8; ++counter) {
		matrices[ allocated ].columns[ counter ] = 0;
		matrices[ allocated ].rows[ counter ] = 0;}
	for( counter = 0; counter < num_columns; ++counter ) {
		if ( init_pin( columns[counter],true ) )
			return ( keymatrix_t * ) NULL;
		matrices[ allocated ].columns[ counter ] = columns[ counter ]; }
	for( counter = 0; counter < num_rows; ++counter ) {
		if ( init_pin( rows[ counter ],false) )
			return ( keymatrix_t * ) NULL;
		matrices[ allocated ].rows[ counter ] = rows[ counter ]; }
	matrices[ allocated ].num_columns = num_columns;
	matrices[ allocated ].num_rows = num_rows;
	init_pin(PIN_F2,false);
	init_pin(PIN_F3,false);
	return &(matrices[ allocated++ ]); }

/* wrapper to set a pin high/low */
void set_pin( Pin_t pin, char value ) {
	GPIOPinWrite( Pin_port( pin ), Pin_num( pin ), value ? 0xff: 0x00 ); }

/* wrapper to get the value of a pin */
static inline char get_pin( Pin_t pin ) {
	return ( GPIOPinRead( Pin_port( pin ), Pin_num( pin ) ) ) ? 0x01 : 0x00; }

/* read key matrix as bits in row major order.
   keys are read as if they are active high. */
keybits_t scan_matrix( const keymatrix_t *to_scan ){
	uint8_t column, row;
	keybits_t to_return = 0;
	if ( to_scan == ( keymatrix_t * ) NULL ) return ( keybits_t ) 0;
	for( row = 0; row < to_scan->num_rows; ++row ) {
		set_pin( to_scan->rows[ row ], 1 );
		for( column = 0; column < to_scan->num_columns; ++column ) {
			to_return |= get_pin( to_scan->columns[ column ] ) <<
				( ( column * ( to_scan->num_rows ) ) + row ); }
		set_pin( to_scan->rows[ row ], 0 ); }
	return to_return; }
