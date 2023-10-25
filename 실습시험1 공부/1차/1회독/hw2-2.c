#include <stdio.h>

void star(int n);

void main()
{
        int n;
        printf("start from: ");
        scanf("%d", &n);
        star(n);
}

void star(int n)
{
	if (n > 0)
		star(n-1);
        for (int i = 0; i < n; i++)
        	printf("*");
        printf("\n");
}

