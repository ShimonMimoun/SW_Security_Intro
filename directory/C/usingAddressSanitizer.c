#include <stdlib.h>
#include<stdio.h>

// fsanitize=Address

//SUMMARY: AddressSanitizer: heap-use-after-free

char usingAddressSanitizer(){
  char *ptr = (char*)malloc(20 * sizeof(char*));
  free(ptr);
  return ptr[15];
    
}

int main() {
usingAddressSanitizer();
  printf("SUMMARY: AddressSanitizer: heap-use-after-free\n");


}
