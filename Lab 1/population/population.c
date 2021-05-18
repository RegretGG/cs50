#include<stdio.h>
#include<cs50.h>
int get_no_of_years(void);
int starting_population(void);
int final_population(void);
int s;

int main(void){
  s = starting_population();
  int e = final_population();
  int y = 0;
  while (s<e)
  {
    s = s + s/3 - s/4;
    y++;
  }
  printf("Years: %i\n", y);
}

int starting_population(void)
{  
  int a;
  do
  {
      a = get_int("Start size: ");
  }
  while (a < 9);
  return a;
}
int final_population(void)
{
  int b;
  do
  {
      b = get_int("End size: ");
  }
  while (b < s);
  return b;
}