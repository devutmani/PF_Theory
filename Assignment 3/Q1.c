/**
 * Name: Dev Kumar
 * Roll No: 24K-0028
 * Section: AI-1A
 * Desc: PF Assignment 3
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

struct Employee 
{
    int employeeCode;
    char employeeName[50];
    char dateOfJoining[11];
};

void assignValues(struct Employee *employee) 
{
    printf("Enter Employee Code: ");
    scanf("%d", &employee->employeeCode);
    getchar();
    printf("Enter Employee Name: ");
    fgets(employee->employeeName, 50, stdin);
    employee->employeeName[strcspn(employee->employeeName, "\n")] = '\0';
    printf("Enter Date of Joining (YYYY-MM-DD): ");
    scanf("%s", employee->dateOfJoining);
}

int calculateTenure(const char *dateOfJoining) 
{
    int joinYear;
    sscanf(dateOfJoining, "%d", &joinYear);
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    int currentYear = currentTime->tm_year + 1900;
    return currentYear - joinYear;
}

void displayEligibleEmployees(struct Employee employees[], int size) 
{
    int count = 0;
    printf("\nEmployees with more than 3 years of tenure:\n");
    for (int i = 0; i < size; i++) 
    {
        int tenure = calculateTenure(employees[i].dateOfJoining);
        if (tenure > 3) 
        {
            printf("\nEmployee Code: %d\n", employees[i].employeeCode);
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Date of Joining: %s\n", employees[i].dateOfJoining);
            printf("Tenure: %d years\n", tenure);
            count++;
        }
    }
    printf("Total Employees with more than 3 years of tenure: %d\n", count);
}

int main() 
{
    const int SIZE = 4;
    struct Employee employees[SIZE];
    for (int i = 0; i < SIZE; i++) 
    {
        printf("\nEnter details for Employee %d:\n", i + 1);
        assignValues(&employees[i]);
    }
    displayEligibleEmployees(employees, SIZE);
    return 0;
}
