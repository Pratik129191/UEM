//	((a + b/c * d - e) * (f - g)) ...


#include<stdio.h>


void main()
{
	int array[7];
	char value = 'a';
	
	for(int i = 0; i < 7; i++)
	{
		printf("Enter The Value of %c\t", value++);
		scanf("%d", &array[i]);
	}
	
	int result = ((array[0] + array[1] / array[2] * array[3] - array[4]) * (array[5] - array[6]));
	printf("The Result of the Given Expression is: %d", result);
}

