#include <stdio.h>

int linear_search(int arr[], int length, int item);
int main()
{
    printf("How many array elements are there:- ");
    int len;
    scanf("%d",&len);

    int array[len];
    for(int i=0;i<len;i++)
    {
        printf("Element No %d is:- ",i);
        scanf("%d",&array[i]);
    }

    printf("Enter the item to be searched:- ");
    int item;
    scanf("%d",&item);

    int position;
    position=linear_search(array,len,item);
    if(position==-1)
        printf("Item is not present in the array.");
    else
        printf("The item is present at the index %d position.",position);
}

int linear_search(int arr[], int length, int item)
{
    int temp=-1;
    for(int i=0;i<length;i++)
    {
        if (arr[i]==item)
        {
            temp=i;
        }
    }
    return temp;
}