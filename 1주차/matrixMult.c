#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void matmult(int a[][N], int b[][N], int c[][N]);

void main(void)
{
	clock_t start, finish;
	double duration;
	int i, j;
	int a[N][N], b[N][N], c[N][N];

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			a[i][j] = rand() % 10;
			b[i][j] = rand() % 10;
		}

	start = clock();
	matmult(a, b, c);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f seconds\n", duration);
}

void matmult(int a[][N], int b[][N], int c[][N])
{
	int i, j, k;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			c[i][j] = 0;
			for (k = 0; k < N; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
}	
