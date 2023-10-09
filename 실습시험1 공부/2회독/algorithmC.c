#include <stdio.h>
#include <time.h>

void main()
{
	clock_t start, finish;
	double duration;
	int i, j;
	unsigned int n;
	long res;
	
	printf("input a positive int: ");
	scanf("%d", &n);
	
	start = clock();
	
	res = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			res = res + i;
	
	finish = clock();
	duration = (double)(finish-start) / CLOCKS_PER_SEC;
	printf("res = %ld (%f seconds)\n", res, duration);
}
