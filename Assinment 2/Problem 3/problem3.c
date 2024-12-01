#include<stdio.h>
#include<string.h>

int word_compressor(char string[][100] , int number_of_strings , char compressed_strings[][100]);

int main()
{
    int i , j , number_of_strings ;
    printf("ENTER THE NUMBER OF STRINGS:") ;
    scanf("%d",&number_of_strings) ;
    char string[number_of_strings][100] ;
    char compressed_strings[number_of_strings][100] ;
    memset(string,'\0',sizeof(string)) ;
    memset(compressed_strings,'\0',sizeof(compressed_strings)) ;
    getchar() ;
    for(i=0 ; i<number_of_strings ; i++)
    {
        getchar() ;
        printf("ENTER THE %d STRING:",i+1) ;
        fgets(string[i],100,stdin) ;
        string[i][strcspn(string,"\n")] = '\0' ;
    }
    int total_removed = word_compressor(string,number_of_strings,compressed_strings) ;
    for(i=0 ; i<number_of_strings ; i++)
    {
        for(j=0 ; j<strlen(compressed_strings[i]) ; j++)
        {
            if(compressed_strings[i][j]!='\0')
            {
                printf("%c",compressed_strings[i][j]) ;
            }
        }
        printf("\n") ;
    }  
    printf("%d",total_removed) ;
    return 0 ;
}

int word_compressor(char string[][100] , int number_of_strings , char compressed_strings[][100])
{
    int i , j , removed = 0 ; 
    for(i=0 ; i<number_of_strings ; i++)
    {
        for(j=0 ; j<strlen(string[i]) ; j++)
        {
            if(string[i][j]!='\0')
            {
                if(string[i][j]==string[i][j+1])
                {
                    removed++ ;
                    continue ;
                }
                else
                {
                    compressed_strings[i][j] = string[i][j] ;
                }
            }
        }
    }
    return removed ;
}
