#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("%s\n", argv[1]);
        return 0;
    }
    else
    {
        printf("Error, type again with one command-line argument\n");
        return 1;
    }
}