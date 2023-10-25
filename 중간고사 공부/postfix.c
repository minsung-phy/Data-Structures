#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define TRUE 0
#define FALSE 1

typedef int element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == MAX_STACK_SIZE-1);
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "Stack is full\n");
		return;
	}
	else
		s->stack[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else
		return s->stack[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else
		return s->stack[s->top];
}

element eval(char exp[])
{
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	
	StackType s;
	init(&s);
	
	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';
			push(&s, value);
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch(ch) {
				case '+': 
					push(&s, op1 + op2);
					break;
				case '-':
					push(&s, op1 - op2);	
					break;
				case '*':
					push(&s, op1 * op2);
					break;
				case '/':
					push(&s, op1 / op2);
					break;	
			}
		}
	}
	return pop(&s);
}

void main()
{
	int result;
	char postfix[100];
	
	printf("postfix input: ");
	scanf("%s", postfix);
	
	result = eval(postfix);
	printf("result is %d\n", result);
}
