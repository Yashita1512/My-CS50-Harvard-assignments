#include <cs50.h>
#include <stdio.h>

int digitcount(long cardnum);
int firstdigit(long cardnum);
int seconddigitofAE(long cardnum);
int seconddigitofMC(long cardnum);
int getoddsum(long cardnum);
int getevensum(long cardnum);
int luhsalgo(void);

string checkcc(int count, int cardnum, int cardnum2, int cardnum3, int luhszero);
int sumofodd = 0, sumofeven = 0;
long n;

int main(void)
{
    n = get_long("Number: ");
    printf("%s\n", checkcc(digitcount(n), firstdigit(n), seconddigitofAE(n), seconddigitofMC(n), luhsalgo()));
}


int digitcount(long cardnum)
{
    int count = 0;
    do
    {
      cardnum /= 10;
      count++;
    }
    while (cardnum != 0);
    return count;
}


int firstdigit(long cardnum)
{
   do
    {
       cardnum = cardnum/10;
    }
   while(cardnum >= 10);
    return cardnum;
}

int seconddigitofAE(long cardnum)
{
    long cardnum2 = cardnum % 100000000000000;
    while (cardnum2 >= 10)
    {
       cardnum2 = cardnum2 / 10;
    }
    return cardnum2;
}


int seconddigitofMC(long cardnum)
{
    long cardnum3 = cardnum % 1000000000000000;
    while(cardnum3 >= 10)
    {
        cardnum3 = cardnum3 / 10;
    }
    return cardnum3;
}

int getoddsum (long cardnum)
{
    while (cardnum > 0)
    {
         int odd = cardnum % 10;
         cardnum = cardnum / 100;
         sumofodd += odd;
    }
    return sumofodd;
}

int getevensum(long cardnum)
{
    while (cardnum > 0)
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


int luhsalgo(void)
{
    int luhssum = getoddsum(n) + getevensum(n);
    int luhszero = luhssum % 10;
  return luhszero;
}

string checkcc(int count, int cardnum, int cardnum2, int cardnum3, int luhszero)
{
   if (luhsalgo() == 0   && ((firstdigit(n) == 4 && digitcount(n) == 13) || (firstdigit(n) == 4 && digitcount(n) == 16)))
   {
       return "VISA";
   }

   if (luhsalgo() == 0 && (firstdigit(n) == 3   && (seconddigitofAE(n) == 4 || seconddigitofAE(n) == 7)   &&   digitcount(n) == 15))
   {
      return "AMEX";
   }

   if (luhsalgo() == 0 && (firstdigit(n) == 5   && (seconddigitofMC(n) >= 1  && seconddigitofMC(n) <= 5)    &&   digitcount(n) == 16))
   {
      return "MASTERCARD";
   }

   else
   {
      return "INVALID";
   }
}






