#include <stdbool.h>
#include <stdint.h>

int main( void ) {
  int x = 1;
  __asm("bkpt\n");
  while(x);}
