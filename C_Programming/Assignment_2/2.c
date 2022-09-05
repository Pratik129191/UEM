#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


bool is_fail(int marks[]);
float get_percentage(int marks[]);

int main()
{
	int marks[5];
	printf("<==== Enter The Marks ====>\n");
	for(int i=0; i<5; i++)
	{
		printf("Marks of Subject %d: \t", i+1);
		scanf("%d", &marks[i]);
	}
	
	if(is_fail(marks))
		printf("FAIL");
	else
		printf("Percentage of the Obtained Marks is %f", get_percentage(marks));
}	


bool is_fail(int marks[])
{
	for(int i=0; i<5; i++)
	{
		if (marks[i] < 40)
		{
			return true;
		}
	}
	return false;
}

float get_percentage(int marks[])
{
	float total = 0;
	for(int i=0; i<5; i++)
	{
		total += marks[i];
	}
	total = total / 5;
	return total;
}