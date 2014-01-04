#include "matrix-driver.h"
#include <stddef.h>
#include <inc/hw_gpio.h>

keymatrix_t matricies[num_matricies];
uint32_t allocated = 0;

keybits_t scan_matrix(keymatrix_t *to_scan){
  return (keybits_t) 0;
}

keymatrix_t* init_matrix(){
  if (allocated >= num_matricies) return (keymatrix_t *) NULL;
  else return &(matricies[allocated++]);
}
