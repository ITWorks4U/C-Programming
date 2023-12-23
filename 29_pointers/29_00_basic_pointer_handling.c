#include <stdio.h>
#include <stdlib.h>

/*
	How to understand and use raw pointers in C (and also C++, which is not recommendet)
	correctly including undefined behavior on unmanaged behavior by your own.
*/
struct Example {
	/*	Just a normal member for this structure.	*/
	int i_member;

	/*	A static C-string with up to 100 bytes to store, whereas only up to 99 bytes
	*	can really be used here. The last character represents the null
	*	termination byte (\0). However, it's also possible to exceeds
	*	this limitation with an undefined behavior.
	*/
	char string1[100];

	/*	A dynamic C-string with n bytes of capacity.
	*	Its size depends on the system you're working on. On a 64 bit machine,
	*	no matter which OS you're using, a pointer has a size of 8 bytes.
	*	On a 32 bit machine the size is 4 bytes, and on a 16 bit machine the
	*	size is only 2 bytes.
	*
	*	It doesn't matter how often the asterisk character is in use, the size
	*	won't be changed here.
	*
	*	But how many characters can hold this pointer? It depends on the given
	*	amount of bytes, which has been allocated during runtime.
	*/
	char *string2;
};

int main(void) {
	/*
		To define a dynamic refence, you have to use a function, like malloc, calloc, realloc.
		On some systems other functions, like valloc, kmalloc, aligned_malloc(C 11), dlmalloc, ...
		can also be used, however, mostly malloc is in use.

		Each of these functions returns void*. It looks like a "dynamic pointer", however, that's
		wrong. The type void* is a typeless pointer and it must refer to an object. The function
		itself returns a reference on which memory the amount of required bytes has been created
		to work with our object.

		Attention: Every allocated memory MUST be released by your own, before the application is going to terminate,
		otherwise memory leaks appears. In some cases it MAY ALSO AFFECT your whole machine!

		A memory leak represents a block of n bytes, which are still available, but no pointer refers to this block.
		On the application termination every allocated memory is automatically released, however, on runtime
		it will "break your neck", when you don't mind that.

		There're different ways to allocate memory:
		-	malloc		(C/C++)
		-	calloc		(C/C++)
		-	realloc		(C/C++)
		-	valloc		(C/C++; may work, but it's not a guarantee)
		-	new			(C++ only)
		
		attention:	Unlike to C, in C++ you MUST cast it to your specified data type, because
					every function (except new) returns void*

		There're two ways to releasing allocated memory:
		-	free		(C/C++)
		-	delete		(C++ only)

		Fun fact:	In C++ you might use new to allocate memory and use the C-function free()
					to release this memory, as well as, by using malloc() to allocate and
					delete to remove this allocated memory. But that's not recommented.

		------------------------------
		>>	Allocate memory of n bytes. It returns an address, where n bytes are now
		>>	available, however, you don't know, which value represents your pointer address,
		>>	depending on your used field, like int*, long*, struct*, ...
		void *malloc(size_t __size);

		------------------------------
		>>	Acts like malloc, however, your object is initialized with a
		>>	default value, depending on the data type.
		>>	argument #0:		how many times an object needs to be allocated
		>>	argument #1:		the amount of bytes for each object
		void *calloc(size_t __nmemb, size_t __size);

		------------------------------
		>>	Reallocating more memory for an already allocated pointer.
		>>	It can also be used to allocate memory for the first time.
		>>	argument #0:		pointer to use (can be NULL / nullptr in C++)
		>>	argument #1:		additional amount of bytes
		void *realloc(void *__ptr, size_t __size);

		------------------------------
		>>	MAY work like malloc/calloc/realloc, may also cause
		>>	an error on compile or runtime. => Hardly used.
		void *valloc(size_t __size);

		------------------------------
		>>	Releasing memory in C/C++:
		void free(void* __ptr);
		
		ATTENTION:	__ptr MUST be allocated by malloc, calloc, realloc (valloc), ... before,
					otherwise a segmentation fault occurs

					Often misunderstood: By using a pointer it doesn't mean, that this is
					always going to store on the heap. Even the stack can also hold pointers,
					however, it depends on if the pointer has a fixed size or a dynamically
					size during the runime. So, if you're using a pointer with a fixed size,
					this is often stored on the stack and by using a function like free() or
					delete expression in C++ a segmentation fault often occurs.

		------------------------------
		>>	Releasing memory in C++ only:
		delete ptr;

		Even your pointer has been successfully freed/deleted from memory, your pointer
		STILL EXISTS to that address, which has been used before! But by using the pointer
		after free()/delete, you'll get a segmentation fault, because this address is no
		longer assigned to that pointer. Assigning with NULL (C) / nullptr (C++) helps you
		define this pointer as invalid.

		There're also programs, which helps you to reveal potentially memory leaks in your
		application. On Linux you can use the program "valgrind". Other applications, like
		DrMemory, PVS studio, ... are also very useful!
	*/

	/*
		In C it's an advise, in C++ it's required to use a cast for memory allocation.
	*/
	struct Example *ex = (struct Example *) malloc(sizeof(struct Example));

	/*	Typical way to check, if "any error" appeared here.	*/
	if (ex == NULL) {
		perror("malloc()");																					//	typical way for "any error"
		return EXIT_FAILURE;
	}

	/*	Are you surprised about the wrongly size of "myStruct"?
	*
	*	In UNIX/Linux sizeof is often defined as "unsigned long", which means the formatting string "%lu" is in use here.
	*	In Windows it's often an "unsigned long long" (%llu), but can also be "just" an unsigned int (%u).
	*/
	printf("size of ex = %lu bytes <=> size of Example = %lu bytes\n", sizeof(ex), sizeof(struct Example));
	printf("location of ex: %p\n", ex);

	/*	releasing the allocated memory	*/
	free(ex);

	/*	it's optional, but you can do this, too	*/
	ex = NULL;				//	C
	// ex = nullptr;		//	C++

	return EXIT_SUCCESS;
}