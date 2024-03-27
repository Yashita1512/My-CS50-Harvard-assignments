#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string word);

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        printf("%s\n", replace(argv[1]));
        return 0;
    }
    else
    {
        printf("Error, type again with one command-line argument\n");
        return 1;
    }
}

string replace(string word)
{
    // const int W = ;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    char novowels[] = {'6', '3', '1', '0', 'u'};

   for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < strlen(word); j++)
        {
            if (vowels[i] == word[j])
            {
                word[j] = novowels[i];
            }
        }
    }
return word;
}
