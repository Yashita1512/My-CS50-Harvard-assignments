#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int lower_bound = 0;
    int upper_bound = 1;

    // Generate a random number within the specified range
    int random_number = rand() % 2;
    // Print the random number
    printf("Random Number in the range [%d, %d]: %d\n", lower_bound, upper_bound, random_number);

    return 0;
}
