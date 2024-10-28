#include <stdio.h>
#include <stdlib.h> 
#include "fibonacci.h"

int main(void)
{
  //unsigned int *fibonacci = fib_jono(15);
  fib_jono(15);
  /*

  int i = 0;
  for(i = 0; i < 15; ++i)
  {
    printf(" %u", fibonacci[i]);
  }
  printf("\n");
  free(fibonacci);
  */
  return 0;
}


void fib_jono(int n){
  int f0 = 0;
  int f1 = 1;
  int next = f0 + f1;

  printf("%d %d ", f0, f1);

  for(int i = 3; i <= n; ++i){
    printf("%d ", next);
    f0 = f1;
    f1 = next;
    next = f0 + f1;
  }
  printf("\n");

}