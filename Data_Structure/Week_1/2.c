#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char str[20];
    printf("Enter The String:\t");
    scanf("%s", &str);


    // reversing the string ===>
    char strc[20], k=0;
    for (int i = strlen(str) - 1; i >= 0; --i) {
        strc[k] = str[i];
        k++;
    }

    // checking the palindrome condition ==>
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] != strc[i]) {
            printf("String is Not Palindrome.");
            exit(0);
        }
    }

    printf("String is Palindrome.");
}