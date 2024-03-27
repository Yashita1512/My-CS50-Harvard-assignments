#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool onlyalphabets(string text);
bool invalidkey(string text);



int main(int argc, string argv[])
{
    int N = strlen(argv[1]);
    for (int i = 0; i < N; i++)
    {
        for (int n = 0; n < i; n++)
        {
            if (argv[1][i] == argv[1][n])
            {
                printf("No duplicate characters allowed in the key\n");
                return 1;
            }

            else
            {
                printf("key is fine\n");
                return 0;
            }
        }

        for (int n = 0; i < n < N; n++)
        {
            if (argv[1][i] == argv[1][n])
            {
                printf("No duplicate characters allowed in the key\n");
                return 1;
            }
            else
            {
                printf("key is fine\n");
                return 0;
            }
        }
    }
}



