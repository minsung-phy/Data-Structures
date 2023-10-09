#include <stdio.h>

void hanoi(int n, char from, char tmp, char to)
{
	if (n == 1)
		printf("Circle 1: %c -> %c\n", from, to);
	else {
		hanoi(n-1, from, to, tmp);
		printf("Circle %d: %c -> %c\n", n, from, to);
		hanoi(n-1, tmp, from, to);
	}
}

void main()
{
	hanoi(3, 'A', 'B', 'C');
}
