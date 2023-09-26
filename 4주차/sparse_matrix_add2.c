#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct {
	element data[MAX_TERMS];
	int rows; // # of rows
	int cols; // # of columns
	int terms; // # of terms (값 개수)
} SparseMatrix;

SparseMatrix sparse_matrix_add2(SparseMatrix a, SparseMatrix b);

void main()
{
	SparseMatrix m1 = { {{1,1,5}, {2,2,9}}, 3,3,2 };
	SparseMatrix m2 = { {{0,0,5}, {2,2,9}}, 3,3,2 };
	SparseMatrix m3;
	m3 = sparse_matrix_add2(m1, m2);
}
	
// addition function of sparse matrix
// c = a + b
SparseMatrix sparse_matrix_add2(SparseMatrix a, SparseMatrix b)
{
	SparseMatrix c;
	int ca = 0, cb = 0, cc = 0; // index pointing to the terms in each array
	// check if array a and array b are the same size
	if (a.rows != b.rows || a.cols != b.cols) {
		fprintf(stderr, "Size error\n");
		exit(1);
	}
	c.rows = a.rows; // c의 행 개수	
	c.cols = a.cols; // c의 열 개수
	c.terms = 0; // 값 개수 초기화	
	while (ca < a.terms && cb < b.terms) {
		// Calculate the srquential number of each term
		int inda = a.data[ca].row * a.cols + a.data[ca].col;
		int indb = b.data[cb].row * b.cols + b.data[cb].col;
		if (inda < indb) // if a term of array 'a' is in front
			c.data[cc++] = a.data[ca++];
		else if (inda == indb) {
			// if the position of a and b are same
			if ((a.data[ca].value + b.data[cb].value) != 0) {
				c.data[cc].row = a.data[ca].row;
				c.data[cc].col = a.data[ca].col;
				c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
			}
			else {
				ca++; cb++;
			}
		}
		else // if a term of array 'b' is in front
			c.data[cc++] = b.data[cb++];
	}
	// Move the remaining terms in arrays 'a' and 'b' to array 'c'.
	for (; ca < a.terms; )
		c.data[cc++] = a.data[ca++];
	for (; cb < b.terms; )
		c.data[cc++] = b.data[cb++];
	c.terms = cc;
	return c;
}
