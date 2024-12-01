/*
  Name: Dev Kumar
  RollNo: 24K-0028
  Section: AI-1A
  Desc: PF Assignment 2
*/

#include <stdio.h>

int secondMini(int arr[], int size);
int main()
{
    int length;
    printf("Enter length of array: ");
    scanf("%d", &length);

    int arr[length];
    for (int i=0; i<length; i++)
    {
        printf("Enter number %d element: ", i+1);
        scanf("%d", &arr[i]);
    }
    if(length==1)
    {
        printf("No Second Smallest number available...");
        return 1;
    }
    printf("Second Smallest number is: %d", secondMini(arr, length));
}

int secondMini(int arr[], int size)
{
    int mini=arr[0];
    int SecMini=arr[1];

    for (int i=2; i<size; i++)
    {
        if(arr[i]>mini && arr[i]<SecMini)
        {
            SecMini=arr[i];
            mini=SecMini;
        }
    }
    return SecMini;
}
