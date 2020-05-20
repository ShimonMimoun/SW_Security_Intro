# SW Security

  
  
  
  
  



##  GCC Sanitize Options
- Modern gcc compiler includes `–fsanitize=<options\>` for catching potential issues.
- Read more: https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html

***Explain :*** 
GCC supports a number of command-line options that control adding run-time instrumentation to the code it normally generates. For example, one purpose of instrumentation is collect profiling statistics for use in finding program hot spots, code coverage analysis, or profile-guided optimizations. Another class of program instrumentation is adding run-time checking to detect programming errors like invalid pointer dereferences or out-of-bounds array accesses, as well as deliberately hostile attacks such as stack smashing or C++ vtable hijacking. There is also a general hook which can be used to implement other forms of tracing or function-level instrumentation for debug or program analysis purposes.

***The purpose:*** 
Small C-language program including four functions each demonstrating a different issue of your choice flagged by GCC-sanitizer.

 - Compiling correctly and not flagged by gcc compiler without `–fsanitize=< option >`
- Relevant `–fsanitize=< option>` shall flag the issue.
###  MemoryNoFree()

*Command:* `gcc -fsanitize=leak`
*ERROR*: ***LeakSanitizer***: detected memory leaks
*But*: Assign memory and do not release it after which will create a memory leak
*Path:* `directory/C/LeakSanitizer.c`

### Stack_Out_OF_BOUNDS()

*Command:* `gcc -fsanitize=address`
*ERROR*: ***AddressSanitizer: stack-buffer-overflow*** on address `<-->`  at pc `<-->` bp `<-->`  sp `<-->`
*But*: I create an array of specific size (in our case of index size), and I try to access the element INDEX + 1 (which does not exist)
*Path:* `directory/C/Stack_Out_OF_BOUNDS.c`

### Undefined()

*Command:* `gcc -fsanitize=undefined`
*ERROR*: ***runtime error: signed integer overflow***: 2147483647 + 1 cannot be represented in type 'int'
*But*: Each variable has a maximum value which defines it, in our case we have price NT_MAX which is defined by +2147483647 (maximum value of an int) and we try to cross this limit
*Path:* `directory/C/Undefined.c`

### UsingAddressSanitizer()

*Command:* `gcc fsanitize=Address`
*ERROR*: ***AddressSanitizer***: heap-use-after-free
*But*: In this example, I'm going to allocate memory to my array, then I'm going to free it and try to read this address (which is already free)
*Path:* `directory/C/usingAddressSanitizer.c`


## Author 
[Shimon Mimoun](https://www.linkedin.com/in/shimonmimoun/)