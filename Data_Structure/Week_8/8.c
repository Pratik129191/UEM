#include <stdio.h>

int interpolation_search(int array[], int length, int item);
int main()
{
    printf("How many elements are in the array:- ");
    int length;
    scanf("%d",&length);

    int array[15];
    for (int i = 0; i < length; ++i)
    {
        printf("Element No %d is:- ",i+1);
        scanf("%d",&array[i]);
    }

    int item;
    printf("Enter the item to search:- ");
    scanf("%d",&item);

    int position;
    position=interpolation_search(array,length,item);
    if(position==-1)
        printf("Element is not in the array.");
    else
        printf("Element is present at the index %d in array.",position);
}

int interpolation_search(int array[], int length, int item)
{
    int low=0,high=length-1;
    int position=0;
    while(low<=high)
    {
        position=(low+(((item-array[low])*(high-low))/(array[high]-array[low])));
        if(array[position]==item)
        {
            return position;
        }
        if(item<array[position])
        {
            high=position-1;
        }
        if(item>array[position])
        {
            low=position+1;
        }
    }
    return -1;
}