#include <stdio.h>

int binary_search(int arr[], int length, int item);
int main()
{
    printf("How many elements are in the array:- ");
    int length;
    scanf("%d",&length);

    int array[length];
    for (int i = 0; i < length; ++i)
    {
        printf("Element No %d is:- ",i+1);
        scanf("%d",&array[i]);
    }

    int item;
    printf("Enter the item to search:- ");
    scanf("%d",&item);

    int position;
    position=binary_search(array,length,item);
    if (position==-1)
        printf("Element is not present in the array.");
    else
        printf("Element is present at index %d in the array.",position);
}

int binary_search(int arr[], int length, int item)
{
    int begin=0,end=length-1;
    int mid;
    int temp=-1;
    while(begin<=end)
    {
        mid=(begin+end)/2;
        if(arr[mid]==item)
        {
            temp=mid;
            break;
        }

        if(item>arr[mid])
        {
            begin=mid+1;
        }

        if(item<arr[mid])
        {
            end=mid-1;
        }
    }
    return temp;
}