/**
 * Name: Dev Kumar
 * Roll No: 24K-0028
 * Section: AI-1A
 * Desc: PF Assignment 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char *email);

int main() 
{
    char *email;
    int length;

    printf("Enter your email address: ");
    scanf("%d", &length);

    email = (char *)malloc(length * sizeof(char));

    if (email == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    scanf("%s", email);

    if (validateEmail(email)) 
    {
        printf("Valid Email\n");
    } 
    else 
    {
        printf("Invalid Email\n");
    }

    free(email);
    return 0;
}

int validateEmail(char *email) 
{
    int atSymbolCount = 0, dotCount = 0;
    int i = 0;

    while (email[i] != '\0') 
    {
        if (email[i] == '@') 
        {
            atSymbolCount++;
        } else if (email[i] == '.') 
        {
            dotCount++;
        }
        i++;
    }

    return atSymbolCount == 1 && dotCount >= 1 && i > 0;
}
