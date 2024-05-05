#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PF Assignment Question 3 
//Shoaib Khan
//23P-0007
//Note: For this question, I did alot of extra study and used other concepts as well.
//There are detailed comments to show all the steps.

// Define the number of cards in a poker hand and the maximum length of a card (e.g.,10S)
int numCards = 5;       // We have 5 cards in each player's hand
int maxCardLen = 3;     // Each card has a maximum length of 3haracters (e.g "10S)
// Function to parse a line of input into two separate poker hands
void parseHands(char line[], char player1[][maxCardLen], char player2[][maxCardLen]) {
    //Tokenizing:Breaking down a string of characters into smaller pieces called tokens based on specific conditions
    // Tokenizing the input line to extract individual cards
    char *token = strtok(line, " ");
    int index = 0; // Index to keep track of the current card being processed
    
    // Parsing player 1's hand
    while (token != NULL && index < numCards) {
        strcpy(player1[index], token); // Copying the token (card) into player1's hand
        token = strtok(NULL, " ");     // Move to the next token (card)
        index++;                       // Move to the next position in the hand array
    }
    
    // Reset index for player 2's hand
    index = 0;
    // Parsing player 2's hand
    while (token != NULL && index < numCards) {
    strcpy(player2[index], token); // Copying the token (card) into player2's hand
        token = strtok(NULL, " ");     // Move to the next token (card)
        index++;                       // Move to the next position in the hand array
    }
}

// Function to compare two poker hands and determine the winner
int compareHands(char player1[][maxCardLen], char player2[][maxCardLen]) {
    // Compare the highest card of each hand
    for (int i = 0; i < numCards; i++) {
        // Convert cards to integers for comparison (e.g., "10S" becomes 10)
        int card1 = atoi(player1[i]);
        int card2 = atoi(player2[i]);
        // Compare the current card of player1 with the current card of player2
        if (card1 > card2)
            return 1; // Player 1 wins
        else if (card1 < card2)
            return 2; // Player 2 wins
    }
    
    return 0; // It's a tie if all cards are equal
}

int main() {
    char line[50]; // Assuming the input line won't exceed 50 characters
    int player1Wins = 0, player2Wins = 0, tieCount = 0; // Variables to keep track of wins and ties
    // Welcome message
    printf("Welcome to the Poker Hand Comparator!\n");
    printf("Please enter the poker hands for both players (or type 'quit' or 'exit' to end):\n");
    
    // Read input until user terminates
    while (fgets(line, sizeof(line), stdin)) {
        // Check for termination condition
        if (strcmp(line, "quit\n") == 0 || strcmp(line, "exit\n") == 0)
            break; // Exit the loop if user types 'quit' or 'exit'
        
        // Arrays to store the cards of both players' hands
        char player1[numCards][maxCardLen], player2[numCards][maxCardLen];
        
        // Parse the input line to extract hands for both players
        parseHands(line, player1, player2);
        
        // Compare the hands to determine the winner
        int winner = compareHands(player1, player2);
        
        // Update win counts based on the comparison result
        if (winner == 1)
            player1Wins++; // Increment player 1's win count
        else if (winner == 2)
            player2Wins++; // Increment player 2's win count
        else
            tieCount++;    // Increment tie count
    }
    // Print results
    printf("Player 1 wins: %d\n", player1Wins);
    printf("Player 2 wins: %d\n", player2Wins);
    printf("Ties: %d\n", tieCount);
    printf("Thanks for playing!\n");
    
    return 0;
}
