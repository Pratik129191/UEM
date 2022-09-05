#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num1, num2;
	char operator;
	float result;
	
	printf("Enter The First Number:\t");
	scanf("%d", &num1);	
	
	printf("Enter The Second Number: \t");
	scanf("%d", &num2);
	
	scanf("%c", &operator);
	printf("Enter The Arithmetic Symbol:\t");
	scanf("%c", &operator);
	
	if(operator == '+')
		result = num1 + num2;
	else if (operator == '-')
		result = num1 - num2;
	else if (operator == '*')
		result = num1 * num2;
	else if (operator == '/' || operator == '%')
		if (num2 == 0)
		{
			printf("Denominator Can't be 0.\nSystem Terminated.");
			exit(0);
		}
		else
		{
			if (operator == '/')
				result = num1 / num2;
			else
				result = num1 % num2;
		}
	printf("The Result of this operation is: %f\t", result);
			
}
