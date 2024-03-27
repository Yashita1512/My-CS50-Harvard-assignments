#include <cs50.h>
#include <stdio.h>

//Definition of the function 'prime'
int min, max;
bool prime(int a)
{
    // TODO
    if (a == 1)
    {
        return false;
    }

    if (a == 2 || a == 3)
    {
        return true;
    }

    for (int n = 2; n < a; n++)
    {
        if (a % n == 0)
        {
            return false;
        }
    }
    return true;
}

//'Main' function
int main(void)
{
    //TODO: take minimum value of range as input
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);


    //TODO: take maximum value of range as input
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    //Checking for numbers being prime by giving a call to the prime function
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            //Printing the prime numbers that the function will verify and hand over
            printf("%i\n", i);
        }
    }
}
