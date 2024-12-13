/**
 * Name: Dev Kumar
 * Roll No: 24K-0028
 * Section: AI-1A
 * Desc: PF Assignment 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Species 
{
    char *name;
    char **supplies;
    int numSupplies;
};

void initializeInventory(struct Species **inventory, int *numSpecies);
void addSupplies(struct Species *species);
void removeSpecies(struct Species **inventory, int *numSpecies, int index);
void displayInventory(struct Species *inventory, int numSpecies);

int main() 
{
    struct Species *inventory;
    int numSpecies;

    initializeInventory(&inventory, &numSpecies);

    displayInventory(inventory, numSpecies);

    for (int i = 0; i < numSpecies; i++) 
    {
        free(inventory[i].supplies);
    }
    free(inventory);
    return 0;
}

void initializeInventory(struct Species **inventory, int *numSpecies)
{
    printf("Enter the number of species: ");
    scanf("%d", numSpecies);

    *inventory = (struct Species *)malloc(*numSpecies * sizeof(struct Species));

    for (int i = 0; i < *numSpecies; i++) 
    {
        printf("Enter species name: ");
        scanf("%s", (*inventory)[i].name);
        (*inventory)[i].numSupplies = 0;
        (*inventory)[i].supplies = NULL;
    }
}

void addSupplies(struct Species *species)
{
    printf("Enter the number of supplies for %s: ", species->name);
    int numSupplies;
    scanf("%d", &numSupplies);

    species->supplies = (char **)malloc(numSupplies * sizeof(char *));
    for (int i = 0; i < numSupplies; i++) 
    {
        species->supplies[i] = (char *)malloc(50 * sizeof(char));
        printf("Enter supply %d: ", i + 1);
        scanf("%s", species->supplies[i]);
    }
    species->numSupplies = numSupplies;
}

void removeSpecies(struct Species **inventory, int *numSpecies, int index)
{
    for (int i = index; i < *numSpecies - 1; i++) 
    {
        (*inventory)[i] = (*inventory)[i + 1];
    }
    (*numSpecies)--;
    free((*inventory)[*numSpecies].supplies);
    (*inventory) = (struct Species *)realloc(*inventory, *numSpecies * sizeof(struct Species));
}

void displayInventory(struct Species *inventory, int numSpecies)
{
    for (int i = 0; i < numSpecies; i++) 
    {
        printf("Species: %s\n", inventory[i].name);
        for (int j = 0; j < inventory[i].numSupplies; j++) 
        {
            printf("  - %s\n", inventory[i].supplies[j]);
        }
        printf("\n");
    }
}
