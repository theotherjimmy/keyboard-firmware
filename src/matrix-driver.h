#ifndef __KekMatrix__
#define __KekMatrix__

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t keybits_t ;

typedef struct keymatrix_t{
  uint32_t columns[5];
  uint32_t rows[3];
} keymatrix_t;

#define num_matricies (2)

keybits_t scan_matrix(keymatrix_t *to_scan);
keymatrix_t* init_matrix();

#endif
