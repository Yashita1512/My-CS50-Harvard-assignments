#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int rotate(int pc, int key);
bool only_digits(string text);

int main(int argc, string argv[])
{
    // Checking whether the program was run with just one command-line argument which is a non negative integer
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        // Converting the CLA from a 'string' to an 'int'
        int k = atoi(argv[1]);

        //Prompt user for text to be ciphered and storing its size
        string p = get_string("plaintext:  ");
        int P = strlen(p);

        //Creating an array of same size as entered text to store each character of rotated/ ciphered text
        char c[P];
        int i = 0;

        //Extracting each character of input text, rotating it and then storing it in the above array
        for (; i < P; i++)
        {
            char pc = p[i];
            c[i] = rotate(pc, k);
        }
        c[i] = '\0';

        //Printing the rotated array i.e. ciphertext
        printf("ciphertext: %s\n", c);
        return 0;
    }
}

//Function to check if the single CLA has all digits only and no alphabets or special characters
bool only_digits(string text)
{
    for (int j = 0; j < strlen(text); j++)
    {
        if (isdigit(text[j]) == 0)
        {
            return false;
        }
    }
    return true;
}

//Function that takes character input but as its ASCII value (integer) and rotates it following Caeser's algorithm
int rotate(int pc, int key)
{
    //Check if the character is an alphabet, lower or uppercase
    if ((pc >= 65  && pc <= 90) || (pc >= 97  && pc <= 122))
    {
        //Adding the key to the character so that it is converted to a cipher character
        int c = (pc + key);

        //Making sure to circle back from z to a or Z to A
        if (c <= 65  || (c >= 90 && c <= 97)  || c >= 122)
        {

            if (c < 65)
            {
                c = c % 26;
                while (c < 65 || c > 90)
                {
                    c += 26;
                }
            }

            if (c > 65)
            {
                c = c % 26;
                while (c < 97 || c > 122)
                {
                    c += 26;
                }
            }

            return c;
        }

        else
        {
            return c;
        }
    }

    else
    {
        return pc;
    }
}




