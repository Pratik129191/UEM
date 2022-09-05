#include<stdio.h>

void main()
{
	int number;
	printf("Enter The Number: \t");
	scanf("%d", &number);
	
	(number % 2 == 0) ? printf("EVEN") : printf("ODD");
}
