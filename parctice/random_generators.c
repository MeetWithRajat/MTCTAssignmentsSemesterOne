#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL));  // Seed the random number generator with the current time

    for (int i = 0; i < 5; i++) {
        printf("%d\n", rand());
    }
    // Generate a random number within the specified range
    // random_input = rand() % (max_range - min_range + 1) + min_range;
    return 0;
}
