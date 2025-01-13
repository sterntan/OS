#include <stdio.h>

// Function prototype
int add(int *a, int *b, int *c);

int main() {
    int num1, num2, num3, sum;

    // Prompt user for input
    printf("Enter first integer: ");
    if (scanf("%d", &num1) != 1) {
        printf("Invalid input. Please enter integers only.\n");
        return 1;
    }

    printf("Enter second integer: ");
    if (scanf("%d", &num2) != 1) {
        printf("Invalid input. Please enter integers only.\n");
        return 1;
    }

    printf("Enter third integer: ");
    if (scanf("%d", &num3) != 1) {
        printf("Invalid input. Please enter integers only.\n");
        return 1;
    }

    // Call add function
    sum = add(&num1, &num2, &num3);

    // Display the result
    printf("The sum is: %d\n", sum);
    return 0;
}

// Function to add three integers passed by reference
int add(int *a, int *b, int *c) {
    return (*a) + (*b) + (*c);
}
