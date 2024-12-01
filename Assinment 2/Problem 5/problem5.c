/*
  Name: Dev Kumar
  RollNo: 24K-0028
  Section: AI-1A
  Desc: PF Assignment 2
*/

#include<stdio.h>

int main()
{
    int size , i , j;
    printf("ENTER THE SIZE OF ARRAY:");
    scanf("%d",&size);
    int array[size];
    for(i=0 ; i<size ; i++)
    {
        printf("ENTER THE VALUE THAT YOU WANT TO STORE ON COLUMN %d:",i+1) ;
        scanf("%d",&array[i]);
    }
    printf("HORIZONTAL HISTOGRAM:\n");
    for(i=0 ; i<size ; i++)
    {
        printf("Value %d: ",i+1);
        for(j=0 ; j<array[i] ; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("VERTICAL HISTOGRAM:\n");
    int max = array[0];
    for(i=0 ; i<size ; i++)
    {
        if(array[i]>max)
        {
            max = array[i];
        }
    }
    int vertical_array[max][size];
    for(i=max-1 ; i>=0 ; i--)
    {
        for(j=0 ; j<size ; j++)
        {
            if(array[j]>i)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }   
        }
        printf("\n");
    }
    for(i=0 ; i<size ; i++)
    {
        printf("%d ",array[i]) ;
    }
    return 0 ;
}
