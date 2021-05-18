#include<stdio.h>
#include<cs50.h>
int get_value_in_right_range(void);


int main(void)
{
    long height = get_value_in_right_range();
    int b = height;
    for(int i = 0; i<height; i++)
    
    {
        b--;
        for (int a = b; a > 0; a--){
            printf(" ");
        }
        for (int n = 0; n<= i; n++){
            printf("#");
            
        }
        printf("  ");
        
        for (int n = 0; n<= i; n++){
            printf("#");
            
        }
        printf("\n");

    }
}

int get_value_in_right_range(void)
{
    long n;
    do  
    {
        n = get_long("Height");
    }   
    while (n<1 || n>8);
    return n;
}
