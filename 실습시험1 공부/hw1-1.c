#include <stdio.h>
#include <time.h>

void main()
{
	clock_t start, finish;
	float duration;
	long res;
	unsigned int n;
	int i;
	
	printf("input a positive int: ");
	scanf("%d", &n);

	start = clock();

	res = 0;	
	for (i = 1; i <= n; i++) 
		res += i;	
	
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("res = %ld (%f seconds)\n", res, duration);
}

