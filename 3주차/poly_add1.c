#include <stdio.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct { // Declare polynomial struct type
	int degree; // Order(degree) of a polynomial
	float coef[MAX_DEGREE]; // Coefficients of a polynomial
} polynomial;

// C = A+B, where A and B are polynomials

polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C; // a Polynomial which contains the result of A+B
	int Apos=0, Bpos=0, Cpos=0; // array index
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // degree of a polynomial C
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void main()
{
	polynomial a = {4, {7, 8, 1, 0, 3}};
	polynomial b = {3, {5, 0, 0, 7}};
	polynomial c;
	c = poly_add1(a, b);
}
