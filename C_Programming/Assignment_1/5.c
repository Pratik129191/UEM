#include<stdio.h>

int main()
{
	int basic, da, hra;
	float gross;
	da = 45; hra = 15;
	
	printf("Enter The basic Salary of the Employee:\t");
	scanf("%d", &basic);
	
	gross = basic + ((basic * da) / 100) + ((basic * hra) / 100);
	printf("The Gross Salary of the Employee is %f.", gross);
}