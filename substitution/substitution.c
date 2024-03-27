#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool onlyalphabets(string text);
bool invalidkey(string text);
string alphabet_arrayU(void);
string alphabet_arrayl(void);

char encoder(char text, string key, string ucalpha, string lcalpha);

static char U[26], l[26], cipher;

int main(int argc, string argv[])
{
    //Checking if the key is valid
    //Checking if the key is valid
    //Checking if the key is valid
    //Checking if the key is valid
    //Checking if the key is valid
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Checking number of characters in the key being 26
    int i = 0, j = 0, N = strlen(argv[1]);
    if (N != 26)
    {
        printf("Key must contain 26 characters only.\n");
        return 1;
    }

    // check if all characters in the CLA i.e. key are alphabets of either of the cases.
    for (; i < N; i++)
    {
        if (argv[1][i] < 'A' || (argv[1][i] > 'Z' && argv[1][i] < 'a') || argv[1][i] > 'z')
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        //Checking for uniqueness of characters in the key
        for (int n = 0; n < i; n++)
        {
            if (argv[1][i] == argv[1][n])
            {
                printf("No duplicate characters allowed in the key\n");
                return 1;
            }
        }

        for (int n = i + 1; n < N; n++)
        {
            if (argv[1][i] == argv[1][n])
            {
                printf("No duplicate characters allowed in the key\n");
                return 1;
            }
        }
    }

    //If the user has provided a valid key proceed with encryption as follows

    //Prompt user for message to encode
    string p = get_string("plaintext: ");
    int P = strlen(p);
    char c[P];

    //Storing each character of the message in pc and encrypting it to c using the encoder function
    for (; j < P; j++)
    {
        char pc = p[j];
        c[j] = encoder(pc, argv[1], alphabet_arrayU(), alphabet_arrayl());
    }
    //adding last character as NULL so as to avoid printing of garbage values
    c[j] = '\0';

    printf("ciphertext: %s\n", c);
    return 0;
}


//defining and populating upper and lower case arrays using their ASCII value ranges and do-while and forloops
string alphabet_arrayU(void)
{
    int j = 65;
    do
    {
        for (int i = 0; i < 26; i++)
        {
            U[i] = j;
            j++;
        }
    }
    while (j < 91);
    return U;
}

string alphabet_arrayl(void)
{
    int k = 97;
    do
    {
        for (int i = 0; i < 26; i++)
        {
            l[i] = k;
            k++;
        }
    }
    while (k < 123);
    return l;
}


//Checking if letters in user message are the letters in alphabets arrays
char encoder(char text, string key, string ucalpha, string lcalpha)
{
    if ((text >= 'a' || text >= 'A') && (text <= 'z' || text <= 'Z'))
    {
        for (int m = 0; m < 26; m++)
        {
            if (text == ucalpha[m] || text == lcalpha[m])
            {
                cipher = key[m];
            }
        }
        if (islower(text) != 0)
        {
            cipher = tolower(cipher);
        }
        if (isupper(text) != 0)
        {
            cipher = toupper(cipher);
        }
    }
    else
    {
        cipher = text;
    }
    return cipher;
}



