#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //TODO: asks user for their name
    string s = get_string("What is your name?");

    //Greet the user with their name
    printf("Hello, %s!\n", s);

}