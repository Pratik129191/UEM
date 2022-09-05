#include<stdio.h>


void main()
{
	int first;
	printf("Enter The First Number: ");
	scanf("%d", &first);
	
	int second;
	printf("Enter The Second Number: ");
	scanf("%d", &second);
	
	printf("<==== After Reversing The Values are ====>\n");
	first = first + second;
	second = first - second;
	first = first - second;
	
	printf("First:---> %d\n", first);
	printf("Second:---> %d\n", second);
}
