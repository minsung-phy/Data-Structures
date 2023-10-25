#include <stdio.h>
#include <string.h>

typedef struct person {
	char name[10];
	int age;
	float height;
} person;

void compare(person a, person b)
{
	if (a.age > b.age)
		printf("a is order than b\n");
	else if (a.age == b.age)
		printf("a is the same age as b\n");
	else
		printf("a is younger than b\n");
}

void main()
{
	person a, b;
	
	strcpy(a.name, "Alice");
	a.age = 15;
	a.height = 50.5;
	
	printf("enter b's age: ");
	scanf("%d", &b.age);
	compare(a, b);
	
	b = a;
	
	printf("a.age = %d, b.age = %d\n", a.age, b.age);
}
