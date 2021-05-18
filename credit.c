#include<stdio.h>
#include<cs50.h>
int main(void)
{
    long n = get_long("Number:");
    long sum = 0;
    long place = 1;
    long a;
    int digit1;
        int digit2 = 0;

    while(true){
        a = n%10;
        if (place%2 == 0){
            int b = 2*a;
            if (b>9){
                sum += b%10 + b/10 ;
            }
            else{
                sum+= 2*a;
            }
        }
        else if (place%2 == 1)
        {
            sum = sum+a;
        }
        if (n/100 ==0 &&  n/10 != 0)
        {
            digit2 = a;
        }
        n = n/10;
        place +=1;
        if (n==0)
        {
            digit1 = a;
            break;
        }
        }
        if (sum%10 == 0){
            place -=1;
        if (digit1==4 && (place==13 || place==16))
        {
                printf("VISA\n");
        }

        else if (place==16)
        {
            if (digit1==5 && (digit2>=1 && digit2<=5))
            {
                printf("MASTERCARD\n");
            }
            else {
            printf("INVALID\n");
            }
        }

        else if (place==15)
        {
            if (digit1==3 && (digit2==4 || digit2==7))
            {
                printf("AMEX\n");
            }
            else {
            printf("INVALID\n");
            }
        }
        else {
            printf("INVALID\n");
            };
        }
        else{
            printf("INVALID\n");
        }
}    