#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
char character[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(void){
    string lines = get_string("Text: ");
    float letters = 0;
    float words = 1;
    float S = 0;
    int n = strlen(lines);
    for (int i = 0; i<n; i++){
        if (lines[i] == ' ')
        {
            words+=1;
        }
        else if (lines[i] == '!' || lines[i] == '?' ||lines[i] == '.')
        {
            S+=1;
        }
        else if( lines[i] == 39 || lines[i] == ',')
        {
            true;
         }
        else{
            letters+=1;
        }
    }
    float L = (letters/words)*100;
    S = (S/words)*100;
    float c = 0.0588 * L - 0.296 * S - 15.8;
    float a = c*10;
    int b = (int)a;
    b = b%10;
    if (b>=5){
        c+=1;
    }
    else{
        true;
    }
    int index = (int)c;

    if(index >16)
    {
        printf("Grade 16+\n");
    }
    else if (index<1){
    printf("Before Grade 1\n");}
    else{
        
    
    printf("Grade %i\n", index);
    }

}
