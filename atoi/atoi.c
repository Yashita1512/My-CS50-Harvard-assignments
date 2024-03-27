#include <cs50.h>
#include <stdio.h>
#include <string.h>

long convert(string input);

int main(void)
{
    string input = get_string("Enter an integer: ");

    // Convert string to int
    printf("%ld\n", convert(input));
    return 0;
}

//Recursive function to calculate the number
long convert(string input)
{
    const int I = strlen(input);
    int number = 0;
    int i = I-1, digit[I], sign = 1;
    // TODO

    // if (i < 0)
    // {
    //     return sign * number;
    // }
    // else
    // {
        if (input[i] == ' ' || input[i] == '\n'|| input[i] == '\t')
        {
            i++;
        }

        if (input[i] == '-')
        {
            sign = -1;
            i++;
        }
        if (input[i] >= '0' && input[i] <= '9')
        {
        digit[i] = input[i] - '0';
        input[i] = '\0';
        number = convert(input) * 10 + digit[i];
        }
    // }
    return sign * number;
}