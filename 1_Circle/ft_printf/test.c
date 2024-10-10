#include <stdio.h>

int main()
{
	int a = -2147483648;
	int b = (unsigned int)a;

	printf("%x\n", a);
	printf("%X\n", a);
	printf("%x\n", b);
	printf("%X\n", b);

	return (0);
}