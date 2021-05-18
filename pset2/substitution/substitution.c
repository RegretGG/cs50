#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char character[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


int main(int argc, string argv[])
{ 
    
        
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
                    return 1;

    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
                    return 1;
    }
    else
    {
        for (int i = 0; i<26 ; i++)
        { 
            if (isalpha(argv[1][i]))
            {true;}
            else{
                return 1;
            }
        }
    
    int n = strlen(argv[1]);
    int checker = 0;
    for (int j = 0; j<n ; j++)
    {                
        for (int i = 0; i<n ; i++)
        { 
            if (argv[1][j] == argv[1][i])
            {
                checker+=1;
                if (checker >= 2)
                {
                    printf("All characters must be unique.");
                    return 1;
                }
                
            }
        }
        checker = 0;
    }
        string plaintext = get_string("plaintext: ");
                int len = strlen(plaintext);

        printf("ciphertext: ");
        for (int i = 0; i< len; i++)
        {   if (isalpha(plaintext[i]))
            {
            for (int j = 0; j<26 ; j++)
            {
                
                        if (islower(plaintext[i]) && plaintext[i] == character[j])
                    {
                        printf("%c", tolower(argv[1][j]));
                     }
                    else if (isupper(plaintext[i]) && tolower(plaintext[i]) == character[j])
                    {
                     printf("%c", toupper(argv[1][j]));
                     }
                    
                

                }
        }
        else
              {
                    printf("%c", plaintext[i]);
                }
    }
    
        printf("\n");
        return 0;
    
}
}