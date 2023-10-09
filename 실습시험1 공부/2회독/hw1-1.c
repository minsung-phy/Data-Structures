#include <stdio.h>
#include <time.h>

void main()
{
	clock_t start, finish;
	double duration;
	int i;
	unsigned int n;
	long res;
	
	printf("input a positive int: ");
	scanf("%d", &n);
	
	start = clock();
	res = 0;
	for (i = 1; i <= n; i++)
		res = res + i;
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	
	printf("res = %ld (%f seconds)", res, duration);
}

