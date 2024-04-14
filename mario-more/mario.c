#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        //TODO: Prompt user for height
        h = get_int("Height: ");
    }
     //If height is less than 1 or greater than 8 keep prompting the user
    while ( h < 1 || h > 8);


    for (int i = 0; i < h; i++)
    {
        for (int s = h; s > i + 1; s--)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("  ");

         for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
    printf("\n");
    }

}
