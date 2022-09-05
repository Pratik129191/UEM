#include<stdio.h> 


void main()
{
	int celcius;
	printf("Enter The Celcius Temperature:\t");
	scanf("%d", &celcius);
	
	int farenhite;
	farenhite = ((9 * celcius) / 5) + 32;
	printf("%d Degree Celcius = %d Degree Farenhite.", celcius, farenhite);
}
