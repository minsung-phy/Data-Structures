#include <stdio.h>
#include <time.h>

double factorial_iter(int n);
	
void main()
{
	clock_t start, finish;
	double duration;
	int n;
	double fac;
	
	printf("Input n: ");
	scanf("%d", &n);
	
	start = clock();
	fac = factorial_iter(n);
	finish = clock();
	
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%d! = %.2lf\n", n, fac);
	printf("%f seconds\n", duration);
}

double factorial_iter(int n)
{
	int i, ans = 1;
	for (i = 1; i <= n; i++)
		ans *= i;
	return ans;
}
