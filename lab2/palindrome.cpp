#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
int isPalindrome(int* num);
int isArmstrong(int* num);
int isPerfectNumber(int* num);

int main() {
    int *choice = (int*)malloc(sizeof(int));
    do {
        printf("\nMenu:\n");
        printf("(a) Check Palindrome\n");
        printf("(b) Check Armstrong Number\n");
        printf("(c) Check Perfect Number\n");
        printf("(d) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", choice);

        if (*choice >= 1 && *choice <= 3) {
            // Dynamically allocate memory for the number
            int* number = (int*)malloc(sizeof(int));
            if (number == NULL) {
                printf("Memory allocation failed.\n");
                exit(1);
            }

            printf("Enter a number: ");
            scanf("%d", number);

            switch (*choice) {
                case 1:
                    if (isPalindrome(number)) {
                        printf("%d is a Palindrome.\n", *number);
                    } else {
                        printf("%d is not a Palindrome.\n", *number);
                    }
                    break;
                case 2:
                    if (isArmstrong(number)) {
                        printf("%d is an Armstrong Number.\n", *number);
                    } else {
                        printf("%d is not an Armstrong Number.\n", *number);
                    }
                    break;
                case 3:
                    if (isPerfectNumber(number)) {
                        printf("%d is a Perfect Number.\n", *number);
                    } else {
                        printf("%d is not a Perfect Number.\n", *number);
                    }
                    break;
            }

            // Free the dynamically allocated memory
            free(number);
        } else if (*choice != 4) {
            printf("Invalid choice. Please try again.\n");
        }

    } while (*choice != 4);

    printf("Exiting program. Goodbye!\n");
    return 0;
}

// Function to check if a number is a palindrome
int isPalindrome(int* num) {
    int* original = (int*)malloc(sizeof(int));
    int* reversed = (int*)malloc(sizeof(int));
    *original = *num, *reversed = 0;
    while (*original > 0) {
        *reversed = *reversed * 10 + *original % 10;
        *original /= 10;
    }
    return *num == *reversed;
}

int isArmstrong(int* num) {
     int* original = (int*)malloc(sizeof(int));
     int* digits = (int*)malloc(sizeof(int));
     int* sum = (int*)malloc(sizeof(int));
     *original = *num, *sum = 0, *digits = 0;

    // Calculate the number of digits
    while (*original > 0) {
        (*digits)++;
        (*original) /= 10;
    }

    *original = *num;

    // Calculate the sum of digits raised to the power of 'digits'
    while (*original > 0) {
     int* digit = (int*)malloc(sizeof(int));
        *digit = (*original) % 10;
         int* power = (int*)malloc(sizeof(int));
        *power = 1;

        // Compute digit^digits using a loop
        int *i = (int*)malloc(sizeof(int));
        for ((*i) = 0; (*i) < *digits; (*i)++) {
            (*power) *= (*digit);
        }

        (*sum) += (*power);
        (*original) /= 10;
    }

    return *num == *sum;
}

// Function to check if a number is a Perfect Number
int isPerfectNumber(int* num) {
     int* sum = (int*)malloc(sizeof(int));
    *sum = 0;
    int *i = (int*)malloc(sizeof(int));
    for ((*i) = 1; (*i) <= *num / 2; (*i)++) {
        if (*num % (*i) == 0) {
            *sum += (*i);
        }
    }
    return *num == *sum;
}