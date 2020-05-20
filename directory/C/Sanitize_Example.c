#include <stdlib.h>
#include<stdio.h>
#include <limits.h>


//**********************************************************************************************************
//**********************************************************************************************************
//**************************      1)MemoryNoFree             ***********************************************
//**********************************************************************************************************
//**********************************************************************************************************
//**********************************************************************************************************

//Command : gcc -fsanitize=leak
//  
void MemoryNoFree() {
  //I create memory leaks
  malloc(10);
  printf("1)ERROR: LeakSanitizer: detected memory leaks\n");

}

//**********************************************************************************************************
//**********************************************************************************************************
//**************************      2)Stack_Out_OF_BOUNDS      ***********************************************
//**********************************************************************************************************
//**********************************************************************************************************
//**********************************************************************************************************


#define INDEX 50

// -fsanitize=address
//ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7fffeb8ffac3 
//at pc 0x7fd72b800b35 bp 0x7fffeb8ffa60 sp 0x7fffeb8ffa50

char Stack_Out_OF_BOUNDS(){
        char str [INDEX]; //I create a table of tank of size INDEX and I try to reach a non-existent value
        printf("2) ERROR: AddressSanitizer: stack-buffer-overflow on address\n");
        return str[(INDEX+1)]; 

}

//**********************************************************************************************************
//**********************************************************************************************************
//**************************         3)Undefined             ***********************************************
//**********************************************************************************************************
//**********************************************************************************************************
//**********************************************************************************************************



#define VALUE 2

//-fsanitize=undefined

// INT_MAX	+2147483647	Defines the maximum value for an int.
//runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int'

void Undefined(){
  
  //INT_MAX==2147483647
  int address = INT_MAX;
  address +=VALUE;
    printf("3)runtime error: signed integer overflow: 2147483647 + VALUES cannot be represented in type 'int'\n");

}



//**********************************************************************************************************
//**********************************************************************************************************
//**************************      4)usingAddressSanitizer      *********************************************
//**********************************************************************************************************
//**********************************************************************************************************
//**********************************************************************************************************



// fsanitize=Address

//SUMMARY: AddressSanitizer: heap-use-after-free

char usingAddressSanitizer(){
  char *ptr = (char*)malloc(20 * sizeof(char*));
  free(ptr);
  printf("4)SUMMARY: AddressSanitizer: heap-use-after-free\n");

  return ptr[15];
    
}


//**********************************************************************************************************
//**********************************************************************************************************
//**************************                 Main            ***********************************************
//**********************************************************************************************************
//**********************************************************************************************************
//**********************************************************************************************************

int main(int argc, char **argv) {


printf("\n *********************************************** START ***********************************************\n");
MemoryNoFree();
Stack_Out_OF_BOUNDS();
Undefined();
usingAddressSanitizer();

printf("\n *********************************************** END ***********************************************\n");

    return 0;
}