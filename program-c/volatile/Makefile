all: volatile.asm no-volatile.asm

volatile.asm: volatile
	objdump -d volatile > volatile.asm

no-volatile.asm: no-volatile
	objdump -d no-volatile > no-volatile.asm
	
volatile:  volatile.c
	gcc -o volatile volatile.c -O2 -g

no-volatile:  no-volatile.c
	gcc -o no-volatile no-volatile.c -O2 -g

clean:
	rm volatile no-volatile volatile.asm no-volatile.asm
