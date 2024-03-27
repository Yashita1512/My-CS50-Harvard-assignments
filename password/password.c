#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Function to vallidate a password of datatype string
bool valid(string password);

int main(void)
{
    //getting input from user
    string password = get_string("Enter the password here: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool checklower, checkupper, checkdigit, checkalnum;
    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]) != 0)
        {
            checkupper = true;
        }
        if (islower(password[i]) != 0)
        {
            checklower = true;
        }
        if (isdigit(password[i]) != 0)
        {
            checkdigit = true;
        }

        if (isalnum(password[i]) == 0)
        {
            checkalnum = true;
        }
    }
    if (checklower == true && checkupper == true && checkdigit == true && checkalnum == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
