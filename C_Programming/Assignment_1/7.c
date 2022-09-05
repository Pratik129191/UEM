#include<stdio.h>

void main()
{
	int number;
	printf("Enter The Number:\t");
	scanf("%d", &number);
	
	int sum = 0;
	while(number != 0)
	{
		int temp = number % 10;
		sum += temp;
		number /= 10;
	}
	printf("The Sum of Every Digits is: %d", sum);
}


