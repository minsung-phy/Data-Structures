#include <stdio.h>
#include <time.h>

void main()
{
	clock_t start, finish;
	double duration;
	unsigned int n;
	long res;
	int i, j;
	
	printf("input a positive int: ");
	scanf("%d", &n);
	
	start = clock();
	res = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			res = res + 1;
	finish = clock();
	duration = (double)(finish-start) / CLOCKS_PER_SEC;
	printf("res = %ld (%f seconds)\n", res, duration);
}

