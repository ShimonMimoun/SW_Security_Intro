#include <stdlib.h>
#include <stdio.h>

#define INDEX 50


// -fsanitize=address
//ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7fffeb8ffac3 
//at pc 0x7fd72b800b35 bp 0x7fffeb8ffa60 sp 0x7fffeb8ffa50


char Stack_Out_OF_BOUNDS(){
        char str [INDEX]; 
        return str[(INDEX+1)]; 
}


int main() {

    Stack_Out_OF_BOUNDS();
      printf("ERROR: AddressSanitizer: stack-buffer-overflow on address\n");

}