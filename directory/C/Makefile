GCC=gcc
FADDRESS=-fsanitize=address
FLEAK=-fsanitize=leak
FUNDEF=-fsanitize=undefined

allWith: LeakFlag StackFlag UndeFlag AdressFlag



WITHOUT_FLAG_ALL:
	$(GCC) -o Sanitize_Example.o Sanitize_Example.c && ./Sanitize_Example.o

LeakFlag:
	$(GCC) $(FLEAK) -o LeakFlag.o LeakSanitizer.c
	./LeakFlag.o

StackFlag:
	$(GCC) $(FADDRESS) -o StackFlag.o Stack_Out_OF_BOUNDS.c 
	./StackFlag.o

UndeFlag:
	$(GCC) $(FUNDEF) -o UndeFlag.o Undefined.c
	./UndeFlag.o
AdressFlag:
	$(GCC) $(FADDRESS) -o AdressFlag.o UsingAddressSanitizer.c
	./AdressFlag.o

clean:
	rm -f *.o *.a *.so *.out Sanitize_Example 

git:
	git add --all
	git commit -m "update files"
	git push
	