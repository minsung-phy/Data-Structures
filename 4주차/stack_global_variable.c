#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;

element stack[MAX_STACK_SIZE];
int top = -1;

// check empty state of stack
int is_empty()
{
	return (top == -1);
}

// check full state of stack
int is_full()
{
	return (top == (MAX_STACK_SIZE-1));
}

// add item
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "Stack Overflow\n");
		return;
	}
	else
		stack[++top] = item;
}

// delete top item
element pop()
{
	if (is_empty()) {
		fprintf(stderr, "Stack Underflow\n");
		exit(1);
	}
	else
		return stack[top--];
}

// peek
element peek()
{
	if (is_empty()) {
		fprintf(stderr, "Stack Underflow\n");
		exit(1);
	}
	else
		return stack[top];
}

void main()
{

}
