#include <stdio.h>
#include <cs50.h>

void draw(int height);

int main(void)
{
    int h = get_int("Height: ");
    draw(h);
}

void draw(int height)
{
    if (height <= 0)
    {
        return;
    }
    
    draw(height - 1);

    for(int i = 0; i < height; i++)
    {
        printf("#");
    }
    printf("\n");
}