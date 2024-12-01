#include<stdio.h>
#include<string.h>
int main()
{
    char previous ;
	  int number_of_slogans , maximum_length_of_slogans , i , j , count_of_character = 0 , k ;
    printf("ENTER THE NUMBER OF SLOGANS:") ;
    scanf("%d",&number_of_slogans) ;
    printf("ENTER THE MAXIMUM LENGTH POSSIBLE FOR ANY SLOGAN:") ;
    scanf("%d",&maximum_length_of_slogans) ;
    getchar() ;
    char slogans[number_of_slogans][maximum_length_of_slogans+1] ;
    int count[number_of_slogans][maximum_length_of_slogans] ;
    for(i=0 ; i<number_of_slogans ; i++)
    {
        printf("ENTER THE %d SLOGAN:",i+1) ;
        fgets(slogans[i],maximum_length_of_slogans+1,stdin) ;
        size_t len = strlen(slogans[i]) ;
        if(len>0 && slogans[i][len-1]=='\n') 
        {
            slogans[i][len-1] = '\0' ;
        }
    }
    for(i=0 ; i<number_of_slogans ; i++)
    {
        for(j=0 ; j<strlen(slogans[i]) ; j++)
        {
            count_of_character = 0 ;
            for(k=0 ; k<strlen(slogans[i]) ; k++)
            {
                if(slogans[i][j]==slogans[i][k] && slogans[i][j] != '\n')
                {
                    count_of_character++ ; 
                }
            }
            count[i][j] = count_of_character ;
        }       
    }
    for(i=0 ; i<number_of_slogans ; i++)
    {
        printf("For %s: {",slogans[i]) ;
        for(j=0 ; j<strlen(slogans[i]) ; j++)
        {
            if(count[i][j]!=0 && count[i][j]<2)
            {
                if(j==(strlen(slogans[i])-1))
                {
                    printf("'%c': %d",slogans[i][j],count[i][j]) ;    
                }
                else
                {
                    printf("'%c': %d,",slogans[i][j],count[i][j]) ;
                }
            }
            else if(count[i][j]!=0 && count[i][j]>=2)
            {
                if(slogans[i][j]!=previous)
                {
                    if(j==(strlen(slogans[i])-1))
                    {
                        printf("'%c': %d",slogans[i][j],count[i][j]) ;    
                    }
                    else
                    {
                        printf("'%c': %d,",slogans[i][j],count[i][j]) ;
                    }
                    previous = slogans[i][j] ;
                }
                else
                {
                    continue ;
                }
            }
        }
        printf(" }\n") ;
    }
    return 0 ;
}
