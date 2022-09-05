#include<stdio.h>


void main()
{
	int first;
	printf("Enter The First Number: ");
	scanf("%d", &first);
	
	int second;
	printf("Enter The Second Number: ");
	scanf("%d", &second);
	
	for(int i = 0; i < second; i++)
	{
		first++;
	}
	
	printf("Sum of Given Numbers is: %d", first);
}
