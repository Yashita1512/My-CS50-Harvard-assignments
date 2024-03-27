#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");

    char l[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    const int L = strlen(l), W = strlen(word);
    char u[L];

        for (int i = 0; i < L ; i++)
        {
            u[i] = l[i] - 32;

            for(int j = 0; j < W; j++)
            {
            if(u[i] == word[j] || l[i] == word[j])
                {
                    printf ("%i\n", POINTS[i]);
                }
            }
        }
}
