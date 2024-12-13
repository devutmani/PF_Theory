/**
 * Name: Dev Kumar
 * Roll No: 24K-0028
 * Section: AI-1A
 * Desc: PF Assignment 3
 */

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);

    int **ratings = (int **)malloc(numEmployees * sizeof(int *));

    for (int i = 0; i < numEmployees; i++) 
    {
        ratings[i] = (int *)malloc(numPeriods * sizeof(int));
        for (int j = 0; j < numPeriods; j++) 
        {
            printf("Enter rating for employee %d, period %d: ", i + 1, j + 1);
            scanf("%d", &ratings[i][j]);
        }
    }

    int highestScore = 0, bestEmployee = 0;
    for (int i = 0; i < numEmployees; i++) 
    {
        int totalScore = 0;
        for (int j = 0; j < numPeriods; j++) 
        {
            totalScore += ratings[i][j];
        }
        if (totalScore > highestScore) 
        {
            highestScore = totalScore;
            bestEmployee = i;
        }
    }

    printf("The best employee is: %d\n", bestEmployee + 1);

    for (int i = 0; i < numEmployees; i++) 
    {
        free(ratings[i]);
    }
    
    free(ratings);
    return 0;
}
