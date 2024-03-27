#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    //TODO: Prompt user for height
    do
    {
        h = get_int("Height: ");
    }
    //If height is less than 1 or gretaer than 8 keep prompting the user
    while (h < 1 || h > 8);

    //TODO: Iterate for each line and print the hashes accordingly
    //This loop runs i times till i >= h
    for (int i = 0; i < h; i++)
    {
        //This loop will run d times until d<=i+1 and print spaces times
        for (int d = h; d > i + 1; d--)
        {
            printf(" ");
        }

        //This loop will run j times until j>=i and print # j times
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        //TODO: When one line is done printing that is above for loop exits after j >= i move to next line
        printf("\n");
    }

}