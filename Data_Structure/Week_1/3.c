#include<stdio.h>

int main()
{
    int centigrade;
    printf("Enter The Centigrade Temperature:\t");
    scanf("%d", &centigrade);

    float fahrenheit;
    fahrenheit = ((5 * (float )centigrade)/9) + 32;
    printf("The Converted Temperature is %f", fahrenheit);
}