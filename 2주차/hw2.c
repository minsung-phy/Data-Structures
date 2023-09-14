// star2

#include <stdio.h>

void star(int n);

void main()
{
        int n, i;
        printf("start from: ");
        scanf("%d", &n);
	
	printf("\n");
	
        for (i = 1; i <= n; i++) {
                star(i);
                printf("\n");
        }
}

void star(int n)
{
        if (n == 1)
                printf("*");
        else {
                printf("*");
                n -= 1;
                star(n);
        }
}

