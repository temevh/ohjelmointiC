#include <stdio.h>
#include <stdlib.h> 
#include "fibonacci.h"

int main(void)
{
  unsigned int *fibonacci = fib_jono(15);
  int i = 0;
  for(i = 0; i < 15; ++i)
  {
    printf(" %u", fibonacci[i]);
  }
  printf("\n");
  free(fibonacci);
  return 0;
}