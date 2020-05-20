GCC=gcc

FLAGS= -g -fsanitize=address

all: LeakSanitizer.c Sanitize_Example.c Stack_Out_OF_BOUNDS.c usingAddressSanitizer.c
	$(GCC) useAfterFree.c -o useAfterFree && ./useAfterFree /
	$(GCC) stackUseAfterScope.c -o stackUseAfterScope && ./stackUseAfterScope /
	$(GCC) memoryLeak.c -o memoryLeak && ./memoryLeak /
	$(GCC) stackUseAfterScope.c -o stackUseAfterScope && ./stackUseAfterScope

WITHOUT_FLAG_ALL:
	$(GCC) -o Sanitize_Example Sanitize_Example.c && ./Sanitize_Example

LeakSanitizer:
	$(GCC) $(FLAGS) LeakSanitizer.c -o LeakSanitizer && ./LeakSanitizer 


clean:
	rm -f *.o *.a *.so *.out Sanitize_Example LeakSanitizer



git:clean
	git add --all
	git commit -m "update files"
	git push
	