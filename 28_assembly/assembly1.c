/**
*	How to combine assembly with C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>						//	← optional: useful for data type int32_t instead of int

int main() {
	int summandA = 10;						//	assembly code inside of a C source code:
	int summandB = 20;						//	The instructions below are depending on the running maschine, the operating system and the C compiler,
	int result = 0;							//	thus a block may work or it won't work (fine).

/*
	asm (									//	an inline assembly instruction starts with asm, __asm or __asm__ → depending on the C compiler
		"mov %ax,summandA\n"
		"mov %bx,summandB\n"				//	some assembly code requires a syntax like: asm ("code as string", "next code", "...");	
		"add %ax,%bx\n"						//	it could be required to use the sign % or %% or not
		"mov result,%ax\n"
	);
*/

/*	an assembly block may also looks like: (e. g. Intel 8086 CPU)
	asm {
		mov ax,summandA
		mov bx,summandB
		add ax,bx
		mov result,ax
	}
*/

//	in this case that code works on a Linux Mint 64 bit system:
	asm /*volatile*/ ("addl %%ebx, %%eax;"					//	volatile:= tells the compiler that the value of a variable may change at any time
					: "=a" (result)							//	define output → variable result gets the content of address EAX
					: "a" (summandA), "b" (summandB)		//	define input → get content of variable a and store it to the first
	); 														//	end of assemby instruction

	printf(" %d + %d = %d\n", summandA, summandB, result);	//	print the result to the console

	return EXIT_SUCCESS;
}
