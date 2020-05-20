#include <stdlib.h>
#include<stdio.h>

//gcc -fsanitize=leak

// ERROR: LeakSanitizer: detected memory leaks
void MemoryNoFree() {
  malloc(7);
}
int main() {
  MemoryNoFree();
  printf("ERROR: LeakSanitizer: detected memory leaks\n");
  return 0;
}