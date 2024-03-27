#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO Promp user for message
    string m = get_string("MESSAGE: ");
    int  M = strlen(m);
    int dbinary[8];

    //Iterating over string array 'm' to convert each character to its ascii value
    for (int i = 0; i < M; i++)
    {
        int dnum[M];
        dnum[i] = m[i];

        //Iterating over the resulting ascii values' array to convet each decimal to binary numbers
        do
        {
            for (int  j = 7; j >= 0; j--)  //obtained binary digits will be saved in reverse order in the array dbinary
            {
                dbinary[j] = dnum[i] % 2;
                dnum[i] = dnum[i] / 2;
            }
        }
        while (dnum[i] > 1);

        //Printing light bulbs representing the array dbinary in regular order
        for (int j = 0; j < 8; j++)
        {
            print_bulb(dbinary[j]);
        }

        //New line for each character of the message string m
        printf("\n");
    }


}

//Prniting bulbs for 0 or 1
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
