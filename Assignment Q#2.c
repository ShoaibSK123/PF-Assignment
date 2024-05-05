#include <stdio.h>

//PF ASSIGNMENT QUESTION 2: COLLATZ SERIES
//SHOAIB KHAN
//23P-0007
//NOTE: I have added ALOT of comments for all the misconceptions and explanations.


// Function to calculate the length of the collatz series ofa given number
int collatzLength(int n) {
    int length = 1; // We start with a length of 1 because we always have at least one number in the sequence (the starting number)

    // Keep qepeating until the number become 1
    while (n != 1) {
        // If the number is even, divide it by 2
        if (n % 2 == 0) {
            n = n / 2;
        } 
        // If the number is odd, multiply it by 3 and add 1
        else {
            n = 3 * n + 1;
        }
        length++; // Increase the length of the sequence by 1 for each step
    }
    return length; // Return the total ;ength of the sequence
}

// Function to find the starting number under nn with the longest Collatz sequence
int longestCollatzSequence(int nn) {
    int maxNumber = 0; // Keep track of the starting number with the longest sequence
    int maxLength = 0; // Keep track of the length of the longest sequence

    // Iterate through all numbers from 1 to nn (exclusive)
    for (int i = 1; i < nn; i++) {
        // Calculate the length of the Collatz sequence for the current number
        int length = collatzLength(i);
        
        // If the current sequence is longer than the previous longest one, update the max length and max number
        if (length > maxLength) {
            maxLength = length;
            maxNumber = i;
        }
    }
    return maxNumber; // Return the starting number with the longest sequence
}

// Main functionwhere the program starts executing
int main() {
    int nn; // Variable to store the upper limit entered by the user
    printf("Enter the upper limit: ");
    scanf("%d", &nn); // Read the upper limit entered by the user

    // Find the starting number with the longest Collatz sequence under the given limit N
    int longestStartNumber = longestCollatzSequence(nn);
    // Calculate the length of the longest Collatz sequence
    int longestLength = collatzLength(longestStartNumber);

    // Print the starting number with the longest Collatz sequence and its length
    printf("The starting number under %d with the longest Collatz sequence: %d\n", nn, longestStartNumber);
    printf("The length of the longest Collatz sequence: %d\n", longestLength);

    return 0;
}
