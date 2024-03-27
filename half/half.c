// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float a, b, c, d, y;

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    a = bill* (tax / 100);
    b = bill + a;
    c = b * ((float)tip / 100);
    d = b + c;

    y = d/2;

    return y;
}

int main(void)
{
     float bill_amount = get_float("Bill before tax and tip: ");
     float tax_percent = get_float("Sale Tax Percent: ");
     int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f, each!\n", half(bill_amount, tax_percent, tip_percent));
}

