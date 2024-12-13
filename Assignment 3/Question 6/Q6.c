/**
 * Name: Dev Kumar
 * Roll No: 24K-0028
 * Section: AI-1A
 * Desc: PF Assignment 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Field 
{
    char *cropType;
    int xCoord, yCoord;
    int size;
    int yield;
};

struct Sensor 
{
    int xCoord, yCoord;
    int range;
};

int main() 
{
    int numFields, numSensors;
    printf("Enter the number of fields: ");
    scanf("%d", &numFields);

    printf("Enter the number of sensors: ");
    scanf("%d", &numSensors);

    struct Field *fields = (struct Field *)malloc(numFields * sizeof(struct Field));
    struct Sensor *sensors = (struct Sensor *)malloc(numSensors * sizeof(struct Sensor));

    for (int i = 0; i < numFields; i++) 
    {
        int coveredSensors = 0;
        for (int j = 0; j < numSensors; j++) 
        {
            int distance = abs(fields[i].xCoord - sensors[j].xCoord) + abs(fields[i].yCoord - sensors[j].yCoord);
            if (distance <= sensors[j].range) 
            {
                coveredSensors++;
            }
        }
        printf("Field %d is covered by %d sensors.\n", i + 1, coveredSensors);
    }
    free(fields);
    free(sensors);
    return 0;
}
