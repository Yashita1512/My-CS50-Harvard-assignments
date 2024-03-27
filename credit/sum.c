#include <cs50.h>
#include <stdio.h>

int getevensum (long cardnum);


int main(void)
{
    long cardnum = get_long("Number: ");
    printf ("%i\n", sumofodd);
    printf ("%i\n",getevensum (cardnum));
}




int getevensum (long cardnum)
{
   while(cardnum > 0)
    {
      int even = cardnum % 100;
      even = even / 10;
      int twiceeven = 2 * even;
      cardnum = cardnum / 100;

      if (twiceeven < 10)
         {
           sumofeven += twiceeven;
         }

      else
         {
            int unitsdigit = twiceeven % 10;
            int tensdigit = twiceeven / 10;

            twiceeven = unitsdigit + tensdigit;
            sumofeven += twiceeven;
         }
    }
    return sumofeven;
}


