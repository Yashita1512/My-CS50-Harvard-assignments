#include <cs50.h>
#include <stdio.h>
#include <math.h>

// int odddigits(long cardnum);
long odd;

int main(void)
{
  long n = get_long("Number: ");


   for (int i = 1; i < 16; i++)
   {
      long x = pow (10,i);
      odd = n % x;
      do
      {
         odd = odd/10;
      }
      while(odd >= 10);
   }

   printf("%li\n", odd);
}

// int odddigits(long cardnum)
// {

// return odd;
// }








