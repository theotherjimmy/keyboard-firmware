
#ifndef __MAIN__
#define __MAIN__

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t keybits_t ;

typedef struct keymatrix{
  uint32_t columns[5];
  uint32_t rows[3];
} keymatrix_t;

keybits_t scan_matrix(keymatrix_t *to_scan);
keymatrix_t* init_matrix();

#endif
