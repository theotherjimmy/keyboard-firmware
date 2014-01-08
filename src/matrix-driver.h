#ifndef __KekMatrix__
#define __KekMatrix__

#include <stdbool.h>
#include <stdint.h>

/* types */
typedef enum {
    PIN_A0, PIN_A1, PIN_A2, PIN_A3, PIN_A4, PIN_A5, PIN_A6, PIN_A7,
    PIN_B0, PIN_B1, PIN_B2, PIN_B3, PIN_B4, PIN_B5, PIN_B6, PIN_B7,
    PIN_C0, PIN_C1, PIN_C2, PIN_C3, PIN_C4, PIN_C5, PIN_C6, PIN_C7,
    PIN_D0, PIN_D1, PIN_D2, PIN_D3, PIN_D4, PIN_D5, PIN_D6, PIN_D7,
    PIN_E0, PIN_E1, PIN_E2, PIN_E3, PIN_E4, PIN_E5, PIN_E6, PIN_E7,
    PIN_F0, PIN_F1, PIN_F2, PIN_F3, PIN_F4, PIN_F5, PIN_F6, PIN_F7,
    PIN_COUNT, PORT_COUNT = PIN_COUNT / 8,
} Pin_t;

typedef uint32_t keybits_t ;

typedef struct keymatrix_t{
  uint8_t num_columns;
  Pin_t columns[5];
  uint8_t num_rows;
  Pin_t rows[3];
} keymatrix_t;
/* types */

/* constants */
#define num_matricies (4)
/* constants */

/* function prototypes */
keybits_t scan_matrix(keymatrix_t *to_scan);

keymatrix_t* init_matrix(const Pin_t *columns, uint32_t num_columns,
			 const Pin_t *rows,    uint32_t num_rows);
/* function prototypes */

#endif
