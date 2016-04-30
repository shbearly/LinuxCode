#include <string.h>
/*
To help the compiler determine memory dependencies, you can qualify a pointer, reference, or array with the restrict keyword. The restrict keyword is a type qualifier that may be applied to pointers, references, and arrays. Its use represents a guarantee by the programmer that within the scope of the pointer declaration the object pointed to can be accessed only by that pointer. Any violation of this guarantee renders the program undefined. This practice helps the compiler optimize certain sections of code because aliasing information can be more easily determined. 
*/

void *memcpy_s(void *restrict s1, const void *restrict s2, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		*((char *)s1 + i)  = *((char *)s2 + i);
	}
}
int main(int argc, char *argv[])
{
	char str[] = "Hello World";

	memcpy_s(str, str, strlen(str));
}
