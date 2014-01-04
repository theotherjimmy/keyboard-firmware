#include "matrix-driver.h"
#include <stddef.h>
#include <inc/hw_gpio.h>

keymatrix_t matricies[num_matricies];
uint32_t allocated = 0;

keybits_t scan_matrix(keymatrix_t *to_scan){
  if (to_scan == (keymatrix_t *) NULL) return (keybits_t) 0;
  return (keybits_t) 0;
}

keymatrix_t* init_matrix(Pin_t *columns, uint32_t num_columns,
			 Pin_t *rows,    uint32_t num_rows){
  if ((allocated >= num_matricies) ||
      (num_columns == 0 ) ||
      (num_rows == 0))
    return (keymatrix_t *) NULL;
  else return &(matricies[allocated++]);
}
