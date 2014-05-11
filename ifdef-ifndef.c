/* #ifdef and #ifndef functions */
/* Let's start with syntax! =P */
/* Syntax for #ifdef
		#ifdef macro-name
		statement sequence
		#endif
*/
/* Syntax for #ifndef
		#ifndef macro-name
		statement sequence
		#endif
*/
/*Note: 
If macro-name is defined already in a #define statement, then the block of the respective code will be compiled.
*/
/* Let's begin! */
#include<stdio.h>
#define AshuMeow 22
int main(void)
{
#ifdef AshuMeow
	printf("Hey Ashu! \n");
#else
	printf("Meow Meow! \n");
#endif
#ifndef BowBow
	printf("BowBow not allowed... Meow Meow! \n");
#endif
	return 0;
}
