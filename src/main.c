#include <stdbool.h>
#include <stdint.h>
#include "main.h"
#include "matrix-driver.h"

int main( void ) {
  __asm("bkpt\n");
  keymatrix_t * to_scan = init_matrix();
  while(1){
    scan_matrix(to_scan);
  }
}
