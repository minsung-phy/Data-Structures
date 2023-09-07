#include <stdio.h>
#include <time.h>

void main(void)
{
	clock_t start, finish;
	double duration;
	unsigned int n;
	long res;

	printf("input a positive int: ");
	scanf("%d", &n);
	
	start = clock();
	
	res = n*(n+1) / 2;

	finish = clock();
	
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("res = %ld (%f seconds)\n", res, duration);
} 
