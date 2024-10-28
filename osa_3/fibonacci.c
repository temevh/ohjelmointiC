#include <stdio.h>
#include <stdlib.h> 
#include "fibonacci.h"

int main(void)
{
  int i = 0;
  unsigned int *fibonacci = fib_jono(15);
  fib_jono(15);
  

  for(i = 0; i < 15; ++i)
  {
    printf(" %u", fibonacci[i]);
  }
  printf("\n");
  free(fibonacci);
  
  return 0;
}


unsigned int * fib_jono(unsigned int n){
  int i = 2;

  unsigned int *pArray = malloc(sizeof(unsigned int) * n);
  pArray[0] = 0;
  pArray[1] = 1;

   for (; i < n; ++i) {
    pArray[i] = pArray[i - 1] + pArray[i - 2];
  }

  return pArray;
}