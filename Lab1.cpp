#include <stdio.h>

int main() {

	unsigned char a, b, c, d;
	a = 74 & 111;
	printf("74 AND 111 = (74) = %d\n", a);
	b = 74 ^ 111;
	printf("74 XOR 111 = (37) = %d\n", b);
	c = 74 >> 1;
	printf("74 >> 1 = (37) = %d\n", c);
	d = 28 | -74 & (~36 ^ -28);
	printf("28 OR -74 AND (NOT 36 XOR -28) = (62) = %d\n", d);

	return 0;
}