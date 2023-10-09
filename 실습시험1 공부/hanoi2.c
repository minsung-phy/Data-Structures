#include <stdio.h>

void hanoi(int n, char from, char middle, char to)
{
	if (n == 1)
		printf("Circle 1: %c -> %c\n", from, to);
	else {
		hanoi(n-1, from, to, middle);
		printf("Circle %d: %c -> %c\n", n, from, to);
		hanoi(n-1, middle, from, to);
	}
}

void main()
{
	hanoi(3, 'A', 'B', 'C');
}
