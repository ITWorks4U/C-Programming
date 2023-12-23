#	Pointers in C/C++

With pointers you're able to access to addresses instead of the values, thus
your workflow can be much more faster than expeced, however, by using pointers
it also results a huge risk.

##	Can I use pointers in C as well as in C++?
-	**Pointers should be used on C programming only! In C++ you can work with pointers, but this is NOT recommended, because C++ wasn't designed for working with pointers and it results different behaviors in contrast to C!**

-	**Pointer handling in C differs to C++! In C++ you might work with C code, however, it's unclear, if the result is identical to C!**

##	Are arrays and pointers the same?
*No. Arrays and pointers have a similar usage and/or behavior, but arrays and pointers are never the same!*

##	Is the pointer handling still the same on different machines?
*No. When you're using pointers on a 64 bit machiche (no matter which OS you're working with), the results differs to a 32 bit machine as well as for a 16 bit machine etc.*

##	Content
-	basic pointer handling (C and C++ exclusive)
-	undefined behaviors (There's much more!)
-	difference between arrays and pointers
-	pointer arithmetic
-	knowledge about memory storage (stack, heap)
-	What happens by using pointers wrongly? => Surprise! :D
-	Checking, if an object has been stored on the stack or heap
-	What happens, if the full RAM is in use for our application? => **Use this with care!**
