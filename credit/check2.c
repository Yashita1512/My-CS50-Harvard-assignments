#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int twiceeven, lastdigit, sumofodd = 0, sumofeven = 0;
   long n = get_long("Number: ");

   while(n > 0)
    {
      int odd = n % 10;
      printf("%i\n",odd);

      n = n / 10;
      sumofodd += odd;
    }
    printf("%i\n",sumofodd);

   while(n > 0)
    {
      int odd = n % 10;
      printf("%i\n",odd);

      n = n / 10;
      sumofodd += odd;
    }
    printf("%i\n",sumofodd);
}

   //    if (twiceeven < 10)
   //       {
   //          sumofeven += twiceeven;
   //       }
   //    else
   //       {
   //          int unitsdigit = twiceeven % 10;
   //          int tensdigit = twiceeven / 10;

   //          twiceeven = unitsdigit + tensdigit;
   //          sumofeven += twiceeven;
   //       }
   // }
   // int luhssum = sumofeven + sumofodd;
   // int luhszero = luhssum % 10;

   // printf("%i, %i, %i, %i\n", sumofeven, sumofodd, luhssum, luhszero);
// }




// int digitcount(long cardnum)
// {
//  int count = 0;
//    do
//    {
//       cardnum = cardnum/10;
//       count++;
//    }
//    while (cardnum != 0);
//    return count;
// }

