#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define VALUE 2

//-fsanitize=undefined


// INT_MAX	+2147483647	Defines the maximum value for an int.
//runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int'

void Undefined(){
  
  //INT_MAX==2147483647
  int address = INT_MAX;
  address +=VALUE;
}


int main(int argc, char **argv) {
Undefined();
  printf("\n******PRINT **********\n runtime error: signed integer overflow: 2147483647 + VALUES cannot be represented in type 'int'\n");

  return 0;
}