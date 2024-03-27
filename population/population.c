#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // TODO: Prompt for start size
    int s;
    do
    {
        s = get_int("Start size of the group: ");
    }
    while (s < 9);

    // TODO : Prompt for end size
    int e;
    do
    {
        e = get_int("End size: ");
    }
    while (e < s);

    if (e == s)
    {
        printf("Years: 0 ");
    }
    else
    {
    //TODO: Calculate number of years until we reach threshold
    int n = 0;
    do
    {
        s = s + (s / 3) - (s / 4);
        n++;
    }
    while (e > s);

    //TODO: Print number of years
    printf("Years: %i", n);
    }
}