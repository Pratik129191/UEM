#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
	int x;
	float fx;
	printf("Enter The Value of x:\t");
	scanf("%d", &x);
	
	if (x < 0)
		fx = 1 + (x / (1 + (x * x)));
	else if (x > 0)
		fx = 1 - (x / (1 + (x * x)));
	else
		fx = 0;
	
	printf("The Functional Value of X is: %f", fx);
	
}
